/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:00:12 by sustmas           #+#    #+#             */
/*   Updated: 2023/11/11 18:29:05 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	run_child_process(char **cmd, int output, int pipefd[2], t_data *data)
{
	dup2(data->flag_input, 0);
	if (data->flag_input)
		close(data->flag_input);
	redirection_to_input(cmd, 0, -1);
	if (data->has_pipe)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
	}
	else
	{
		dup2(output, 1);
	}
	redirection_to_output(cmd, 0, 0, 0);
	cmd = re_create_cmd(cmd, 0, -1, 0);
	parse(cmd, data);
	exit(1);
}

int	run_parent_process(t_data *data, pid_t pid, int pipefd[2])
{
	int	status;

	if (data->has_pipe)
	{
		close(pipefd[1]);
		status = waitpid(pid, 0, 0);
		return (pipefd[0]);
	}
	else
	{
		status = waitpid(pid, 0, 0);
		return (0);
	}
}

int	comment(t_data *data, char **cmd, int input, int output)
{
	pid_t	pid;
	int		pipefd[2];

	if (data->has_pipe && pipe(pipefd) == -1)
		return (ft_error("Pipe is not created!\n", 1, data), 1);
	data->flag_input = input;
	pid = fork();
	if (pid < 0)
		return (ft_error("Fork is not created!\n", 1, data), 1);
	else if (pid == 0)
		run_child_process(cmd, output, pipefd, data);
	else
		return (run_parent_process(data, pid, pipefd));
	return (0);
}

void	pipex(t_data *data, int i, int fd)
{
	char	**cmd;

	int (flag) = 0;
	if (data->pipe_count)
		data->arg = ft_split(data->lexer->full_str, '|');
	else
	{
		data->arg = ft_split(data->lexer->full_str, ' ');
		flag = 1;
	}
	while (data->arg[++i] && !flag)
	{
		cmd = ft_split(data->arg[i], ' ');
		if (!i)
			execute_first_command(data, cmd, &fd);
		else if (i == data->pipe_count)
			execute_commands(data, cmd, &fd);
		else
			fd = comment(data, cmd, fd, 1);
		if (cmd)
			ft_free_malloc(cmd);
	}
	data->pipe_count = 0;
}
