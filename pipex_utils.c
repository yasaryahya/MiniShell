/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:46:11 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/11 21:59:23 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>
#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>

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

void	execute_first_command(t_data *data, char **cmd, int *fd)
{
	data->has_pipe = 1;
	*fd = comment(data, cmd, 0, 1);
}

void	execute_commands(t_data *data, char **cmd, int *fd)
{
	data->has_pipe = 0;
	comment(data, cmd, *fd, 1);
}

char	*create_path(char *cmd, char **cmd_paths)
{
	char	*tmp;
	char	*tmp_cmd;
	char	**tmp_cmd_paths;

	tmp_cmd_paths = cmd_paths;
	while (cmd_paths)
	{
		tmp = ft_strjoin(*cmd_paths, "/");
		tmp_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(tmp_cmd, F_OK))
			return (ft_free_str(tmp_cmd_paths), tmp_cmd);
		free(tmp_cmd);
		cmd_paths++;
	}
	return (NULL);
}

char	**re_create_cmd(char **ex_cmd, int len, int i, int j)
{
	char	**cmd;

	while (ex_cmd[++i])
	{
		if (!ft_strncmp(ex_cmd[i], "<", 2) || !ft_strncmp(ex_cmd[i], ">", 2)
			|| !ft_strncmp(ex_cmd[i], "<<", 3) || !ft_strncmp(ex_cmd[i], ">>",
				3))
			i++;
		else
			len++;
	}
	cmd = malloc(sizeof(char *) * (len + 1));
	i = -1;
	j = 0;
	while (ex_cmd[++i])
	{
		if (!ft_strncmp(ex_cmd[i], "<", 2) || !ft_strncmp(ex_cmd[i], ">", 2)
			|| !ft_strncmp(ex_cmd[i], "<<", 3) || !ft_strncmp(ex_cmd[i], ">>",
				3))
			i++;
		else
			cmd[j++] = ft_strdup(ex_cmd[i]);
	}
	cmd[j] = NULL;
	return (cmd);
}
