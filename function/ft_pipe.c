/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:51:04 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/18 06:10:03 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void ft_free_malloc(char **tab)
{
    size_t i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

char	**re_create_cmd(char **ex_cmd, int len, int i, int j)
{
	char	**cmd;

	while (ex_cmd[++i])
	{
		if (!ft_strncmp(ex_cmd[i], "<", 2) || !ft_strncmp(ex_cmd[i], ">", 2)
			|| !ft_strncmp(ex_cmd[i], "<<", 3)
			|| !ft_strncmp(ex_cmd[i], ">>", 3))
			i++;
		else
			len++;
	}
	cmd = malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (ex_cmd[++i])
	{
		if (!ft_strncmp(ex_cmd[i], "<", 2) || !ft_strncmp(ex_cmd[i], ">", 2)
			|| !ft_strncmp(ex_cmd[i], "<<", 3)
			|| !ft_strncmp(ex_cmd[i], ">>", 3))
			i++;
		else
			cmd[j++] = ft_strdup(ex_cmd[i]);
	}

	// Move the call to ft_free_malloc() to the end of the function.
	ft_free_malloc(ex_cmd);

	return (cmd[j] = NULL, cmd);
}


int	operation(char *x)
{
	char	*input;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (perror("Pipe is not created!\n"), exit(1), 1);
	input = readline("> ");
	while (ft_strncmp(input, x, ft_strlen(x) + 1))
	{
		write(pipefd[1], input, ft_strlen(input));
		write(pipefd[1], "\n", 1);
		free(input);
		input = readline("> ");
	}
	close(pipefd[1]);
	free(input);
	return (pipefd[0]);
}
void	redirection_to_output(char **cmd, int i, int fd, int x)
{
	while (cmd[i])
		i++;
	if (i < 2)
		return ;
	while (--i > -1)
	{
		if (!ft_strncmp(cmd[i], ">", 2))
		{
			if (!x++)
			{
				fd = open(cmd[i + 1],
						O_CREAT | O_TRUNC | O_WRONLY, 0000644);
				dup2(fd, 1);
			}
			else
				fd = open(cmd[i + 1], O_CREAT | O_TRUNC, 0000644);
			close(fd);
		}
		else if (!ft_strncmp(cmd[i], ">>", 3))
		{
			if (!x++)
			{
				fd = open(cmd[i + 1], O_CREAT
						| O_APPEND | O_WRONLY, 0000644);
				dup2(fd, 1);
			}
			else
				fd = open(cmd[i + 1], O_CREAT, 0000644);
			close(fd);
		}
	}
}

void	redirection_to_input(char **cmd, int fd, int i)
{
	while (cmd[++i])
	{
		if (!ft_strncmp(cmd[i], "<<", 3))
		{
			if (fd > 0)
				close(fd);
			fd = operation(cmd[i + 1]);
		}
	}
	i = -1;
	while (fd > -1 && cmd[++i])
		if (!ft_strncmp(cmd[i], "<", 2))
			fd = open(cmd[i + 1], O_RDONLY);
	if (fd > 0)
	{
		dup2(fd, 0);
		close(fd);
	}
	else if (fd < 0)
		return (printf("minishell: %s: no such file or directory\n",
				cmd[i + 1]), exit(1));
}


int	comment(t_data *data, char **cmd, int input, int output, int x)
{
	pid_t	pid;
	int		pipefd[2];

	if (x && pipe(pipefd) == -1)
		return (ft_error("Pipe is not created!", 1), 1);
	pid = fork();
	if (pid < 0)
		return (ft_error("Fork is not created!!\n",1),1);
	else if (pid == 0)
	{
		printf("pipe girdi\n");
		dup2(input, 0);
		if (input)
			close(input);
		redirection_to_input(cmd, 0, -1);
		if (x)
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1);
			close(pipefd[1]);
		}
		else
			dup2(output, 1);
		redirection_to_output(cmd, 0, 0, 0);

		// Check if cmd is not null before calling re_create_cmd().
		if (cmd)
			cmd = re_create_cmd(cmd, 0, -1, 0);

		// Check if cmd is still not null after calling re_create_cmd().
		if (cmd)
			parse(data, cmd);
	}
	if (x)
		return (close(pipefd[1]), waitpid(pid, 0, 0), pipefd[0]);
	waitpid(pid, 0, 0);
	return (0);
}



void	ft_pipe(t_data *data)
{
	int		i;
	int		fd;
	char	**cmdd;

	i = -1;
	fd = 0;
	printf("pipe girdi\n");
	data->cmd = ft_split(data->lexer->full_str, '|');
	while (data->cmd[++i])
	{
		cmdd = ft_split(data->cmd[i], ' ');
		if (!i)
			fd = comment(data, cmdd, 0, 1, 1);
		else if (i == data->pipe_count)
			comment(data, cmdd, fd, 1, 0);
		else
			fd = comment(data, cmdd, fd, 1, 1);
		ft_free_malloc(cmdd);
	}
	data->pipe_count = 0;
}