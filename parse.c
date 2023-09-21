/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:33:37 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/21 08:52:24 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsetwo(char **command, t_data *data)
{
	data->cmd_count = 0;
	while (command[data->cmd_count])
		data->cmd_count++;
	//redirection_to_output(command, 0, 0, 0);
	if (ft_strcmp(command[0], "echo") == 0)
		ft_echo(command, 1);
	if (ft_strcmp(command[0], "pwd") == 0)
		ft_pwd(data);
	else if (ft_strcmp(command[0], "/bin/ls") == 0)
		bin_ls(command, data);
	else if (ft_strcmp(command[0], "cd") == 0)
		cd(command, data);
	if (ft_strcmp(command[0], "env") == 0)
		env_print(data, 0);
	else if (ft_strcmp(command[0], "export") == 0)
		export(data, command);
	//else if (ft_strcmp(command[0], "ls") == 0)
	//	printf("ls:girdyahyayasar");
	//else if (ft_strcmp(command[0], "wc") == 0)
	//	printf("wc:girdi");
	//else if (ft_strcmp(command[0], "unset") == 0)
		//unset(command);
	else if (ft_strcmp(command[0], "clear") == 0)
		printf("\033[H\033[J");
	//else if (ft_strcmp(command[0], "exit") == 0)
		//ft_exit(command);
	else
		command_function(data, command);
}

void	parse(char **command, t_data *data)
{
	if (!command || !command[0])
	{
		printf("Command is empty or invalid.\n");
		return ;
	}
	else if (command)
		parsetwo(command, data);
}
