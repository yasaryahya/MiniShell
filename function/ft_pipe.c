/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:51:04 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/20 00:23:38 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

char	**re_create_cmd(char **cmd, int len, int i, int j)
{
    char	**cmdd;

    while (cmd[++i])
    {
        if (!ft_strncmp(cmd[i], "<", 2) || !ft_strncmp(cmd[i], ">", 2)
            || !ft_strncmp(cmd[i], "<<", 3)
            || !ft_strncmp(cmd[i], ">>", 3))
            i++;
        else
            len++;
    }
    cmdd = malloc(sizeof(char *) * (len + 1));
    i = -1;
    while (cmd[++i])
    {
        if (!ft_strncmp(cmd[i], "<", 2) || !ft_strncmp(cmd[i], ">", 2)
            || !ft_strncmp(cmd[i], "<<", 3)
            || !ft_strncmp(cmd[i], ">>", 3))
            i++;
        else
            cmdd[j++] = ft_strdup(cmd[i]);
    }
    return (cmdd[j] = NULL, ft_free_malloc(cmd), cmdd);
}


int	operation(char **cmd, int i)
{
	char	*input;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (perror("Pipe is not created!\n"), exit(1), 1);
	input = readline("> ");
	while (ft_strncmp(input, cmd[i], ft_strlen(cmd[i]) + 1))
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
			fd = operation(cmd, i+1);
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


int comment(t_data *data, char **cmd, int input, int output, int is_pipe)
{
    pid_t pid;
    int pipefd[2];

    if (is_pipe && pipe(pipefd) == -1)
        return (ft_error("Pipe is not created!", 1), 1);
    pid = fork();
    if (pid < 0)
        return (ft_error("Fork is not created!!\n", 1), 1);
    else if (pid == 0)
    {
        dup2(input, 0);
        if (input)
            close(input);
        redirection_to_input(cmd, 0, -1);
        if (is_pipe)
        {
            close(pipefd[0]);
            dup2(pipefd[1], 1);
            close(pipefd[1]);
        }
        else
            dup2(output, 1);
        redirection_to_output(cmd, 0, 0, 0);
        if (cmd)
            cmd = re_create_cmd(cmd, 0, -1, 0);
        if (cmd)
        	parse(data);
    }
    if (is_pipe)
        return (close(pipefd[1]), waitpid(pid, 0, 0), pipefd[0]);
    waitpid(pid, 0, 0);
    return (0);
}

void ft_pipe(t_data *data)
{
    int i;
    int fd;
	char **cmdd;

    i = -1;
    fd = 0;
	
    data->cmd = ft_split(data->lexer->full_str, '|');
    while (data->cmd[++i])
    {
    	ft_free_malloc(data->arg);
    	data->arg = ft_split(data->cmd[i], ' ');
		cmdd = ft_split(data->cmd[i], ' ');
        if (!i)
            fd = comment(data, cmdd, 0, 1, 1);
        else if (i == data->pipe_count)
            comment(data, cmdd, fd, 1, 0);
        else
            fd = comment(data, cmdd, fd, 1, 1);
    }
	ft_free_malloc(data->cmd);
    data->pipe_count = 0;
}