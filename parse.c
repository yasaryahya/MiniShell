/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:33:37 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/23 07:20:03 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_three(char **command, t_data *data, char *new_cmd)
{

	if (ft_strcmp(new_cmd, "unset") == 0)
		unset(data, command);
	else if (ft_strcmp(new_cmd, "clear") == 0)
			printf("\033[H\033[J");
	else if (ft_strcmp(new_cmd, "exit") == 0)
		ft_exit(data);
	else if (((ft_strncmp(&command[0][0], "/" , 1) == 0)
		|| ft_strncmp(&command[0][0], "." , 1) == 0) && data->flag_dollar == 0)
		slash(command, data);
	else
		command_function(data, command);
}

void	parse_two(char **command, t_data *data)
{
	char *new_cmd = NULL;

	new_cmd = to_lowercase(command[0]);
	if (!new_cmd)
		ft_error("malloc hatası", 1, data);
	data->cmd_count = 0;
	while (command[data->cmd_count])
		data->cmd_count++;
	if (ft_strchr(command[0], '=') != NULL)
			ft_arguman_add(command, data);
	else if (ft_strcmp(new_cmd, "echo") == 0)
			ft_echo(command, 1);
	else if (ft_strcmp(new_cmd, "pwd") == 0)
			ft_pwd(data);
	else if (ft_strcmp(command[0], "cd") == 0)
		cd(command, data);
	else if (ft_strcmp(new_cmd, "env") == 0)
			env_print(data, 0);
	else if (ft_strcmp(command[0], "export") == 0)
		export(data, command);
	else
		parse_three(command, data, new_cmd);
	free(new_cmd);
}

void	parse(char **command, t_data *data)
{
	if (!command || !command[0])
	{
		ft_error("Command is empty or invalid.\n", 127, data);
		return ;
	}
	else
		parse_two(command, data);
	return ;
}
