/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:22:08 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/18 06:42:29 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	parsetwo(t_data *data, char **cmd)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(cmd[0], "bin/ls", 7) == 0)
		bin_ls();
	else if (ft_strncmp(cmd[0], "cd", 2) == 0)
		cd(data, cmd);
	else if (ft_strncmp(cmd[0], "env", 3) == 0)
		env_print(data, 0);
	else if (ft_strncmp(cmd[0], "export", 6) == 0)
		export(data);
	else if (ft_strncmp(cmd[0], "unset", 5) == 0)
		unset(data);
	else if (ft_strncmp(cmd[0], "clear", 5) == 0)
		printf("\033[H\033[J");
	else if (ft_strncmp(cmd[0], "exit", 4) == 0)
		ft_exit(data);
	else
		command(data, cmd);
}

void	parse(t_data *data, char **cmd)
{	
	if (!cmd || !cmd[0])
	{
		printf("Command is empty or invalid.\n");
		return;
	}
	if(cmd)
		parsetwo(data, cmd);
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
