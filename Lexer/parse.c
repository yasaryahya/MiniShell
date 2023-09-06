/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:22:08 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/06 05:06:43 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <stdbool.h>

void	 ilkarguman(t_data data)
{	
	if(!data.arg[0] || !data.arg)
		printf("");
	else
		if (ft_strncmp(data.arg[0], "echo", ft_strlen(data.arg[0])) == 0)
			ft_echo(data);
		else if (ft_strncmp(data.arg[0], "pwd", ft_strlen(data.arg[0])) == 0)
		 	ft_pwd();
		else if (ft_strncmp(data.arg[0], "bin/ls", ft_strlen(data.arg[0])) == 0)
		 	bin_ls();
		else if (ft_strncmp(data.arg[0], "ls", ft_strlen(data.arg[0])) == 0)
		 	ls_genel(data);
		else if (ft_strncmp(data.arg[0], "cat", ft_strlen(data.arg[0])) == 0)
		 	cat(data);
		else if (ft_strncmp(data.arg[0], "cd", ft_strlen(data.arg[0])) == 0)
		 	cd(data);
		else if (ft_strncmp(data.arg[0], "touch", ft_strlen(data.arg[0])) == 0)
		 	touch(data);
		else if (ft_strncmp(data.arg[0], "mkdir", ft_strlen(data.arg[0])) == 0)
			ft_mkdir(data);
		else if (ft_strncmp(data.arg[0], "rm", ft_strlen(data.arg[0])) == 0)
			rm(data.arg[1]);
		else if (ft_strncmp(data.arg[0], "grep", ft_strlen(data.arg[0])) == 0)
		 	printf("grep");
		else if (ft_strncmp(data.arg[0], "env", ft_strlen(data.arg[0])) == 0)
		 	ft_env(data);
		else if (ft_strncmp(data.arg[0], "export", ft_strlen(data.arg[0])) == 0)
		 	printf("export");//export(data);
		else if (ft_strncmp(data.arg[0], "unset", ft_strlen(data.arg[0])) == 0)
		 	printf("unset");
		else if (ft_strncmp(data.arg[0], "clear", ft_strlen(data.arg[0])) == 0)
		 	printf("\033[H\033[J");
		else if (ft_strncmp(data.arg[0], "exit", ft_strlen(data.arg[0])) == 0)
		 	ft_exit(data);
		else
			printf("command not found: %s\n", data.arg[0]);
	return ;
}

void tirnak_kontrol(t_data data) {
    bool inside_double_quotes = false;
    bool inside_single_quotes = false;

    int i = 0;
    while (data.b_arg[i]) 
	{
        if (data.b_arg[i] == '"' && !inside_single_quotes)
            inside_double_quotes = !inside_double_quotes;
		else if (data.b_arg[i] == '\'' && !inside_double_quotes)
            inside_single_quotes = !inside_single_quotes;
        i++;
    }

    if (inside_double_quotes || inside_single_quotes) {
        ft_error("parse/ tırnak hatalı", 0);
    }
}



void	parse(t_data data)
{
	tirnak_kontrol(data);
	ilkarguman(data);
	
	return ;
}
