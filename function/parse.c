/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:22:08 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/19 06:18:05 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	parsetwo(t_data *data)
{
	int i = strlen(data->arg[0]);
	if (ft_strncmp(data->arg[0], "echo", i) == 0)
		ft_echo(data);
	else if (ft_strncmp(data->arg[0], "pwd", i) == 0)
		ft_pwd();
	else if (ft_strncmp(data->arg[0], "/bin/ls", i) == 0)
		bin_ls(data);
	else if (ft_strncmp(data->arg[0], "cd", i) == 0)
		cd(data);
	else if (ft_strncmp(data->arg[0], "env", i) == 0)
		env_print(data, 0);
	else if (ft_strncmp(data->arg[0], "export", i) == 0)
		export(data);
	else if (ft_strncmp(data->arg[0], "unset", i) == 0)
		unset(data);
	else if (ft_strncmp(data->arg[0], "clear", i) == 0)
		printf("\033[H\033[J");
	else if (ft_strncmp(data->arg[0], "exit", i) == 0)
		ft_exit(data);
	else
		command(data);
}

void	parse(t_data *data)
{
	if (!data->arg || !data->arg[0])
	{
		printf("Command is empty or invalid.\n");
		return;
	}
	if(data)
		parsetwo(data);
}


int tirnak_kontrol(char *command)
{
    bool inside_double_quotes = false;
    bool inside_single_quotes = false;

    int i = 0;
    while (command[i]) 
	{
        if (command[i] == '"' && !inside_single_quotes)
            inside_double_quotes = !inside_double_quotes;
		else if (command[i] == '\'' && !inside_double_quotes)
            inside_single_quotes = !inside_single_quotes;
        i++;
    }

    if (inside_double_quotes || inside_single_quotes) {
        return 0;
    }
	return 1;
}
