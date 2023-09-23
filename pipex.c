/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:00:12 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/23 05:24:25 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

void	atama(int *pipefd)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
}

int	comment(t_data *data, char **cmd, int input, int output)
{
	pid_t	pid;
	int		pipefd[2];

	if (data->has_pipe && pipe(pipefd) == -1)
		return (perror("Pipe is not created!\n"), exit(1), 1);
	pid = fork();
	if (pid < 0)
		return (perror("Fork is not created!!\n"), exit(1), 1);
	else if (pid == 0)
	{
		dup2(input, 0);
		if (input)
			close(input);
		redirection_to_input(cmd, 0, -1);
		if (data->has_pipe)
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1);
			close(pipefd[1]);
		}
		else
			dup2(output, 1);
		redirection_to_output(cmd, 0, 0, 0);
		cmd = re_create_cmd(cmd, 0, -1, 0);
		//char *a = find_value("PATH", data);
		//char *path = create_path(cmd[0], ft_split(a, ':'));
		//execve(path, cmd, data->envrt );
		parse(cmd, data);
	}
	if (data->has_pipe)
		return (close(pipefd[1]), waitpid(pid, 0, 0), pipefd[0]);
	return (waitpid(pid, 0, 0), 0);
}

void	pipex(t_data *data, int i, int fd)
{
	char	**cmd;

	data->arg = ft_split(data->lexer->full_str, '|');
	while (data->arg[++i])
	{
		cmd = ft_split(data->arg[i], ' ');
		if (!i)
		{
			data->has_pipe = 1;
			fd = comment(data, cmd, 0, 1);
		}
		else if (i == data->pipe_count)
		{
			data->has_pipe = 0;
			comment(data, cmd, fd, 1);
		}
		else
			fd = comment(data, cmd, fd, 1);
		ft_free_malloc(cmd);
	}
	data->pipe_count = 0;
}
