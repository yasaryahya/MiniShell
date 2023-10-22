/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:46:11 by yyasar            #+#    #+#             */
/*   Updated: 2023/10/22 00:17:05 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	i = -1;
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
	//ft_free_malloc(ex_cmd);
	return (cmd);
}
