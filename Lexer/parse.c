/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:22:08 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/02 20:56:11 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
void	 ilkarguman(t_data data)
{	if (strcmp(data.arg[0], "echo") == 0)
		printf("echo");
	else if (strcmp(data.arg[0], "pwd") == 0)
	 	printf("pwd");
	else if (strcmp(data.arg[0], "bin/ls") == 0)
	 	printf("bin/ls");
	else if (strcmp(data.arg[0], "ls") == 0)
	 	printf("ls");
	else if (strcmp(data.arg[0], "cat") == 0)
	 	printf("cat");
	else if (strcmp(data.arg[0], "cd") == 0)
	 	printf("cd");
	else if (strcmp(data.arg[0], "touch") == 0)
	 	printf("touch");
	else if (strcmp(data.arg[0], "mkdir") == 0)
		printf("mkdir");
	else if (strcmp(data.arg[0], "rm") == 0)
		printf("rm");
	else if (strcmp(data.arg[0], "grep") == 0)
	 	printf("grep");
	else if (strcmp(data.arg[0], "env") == 0)
	 	printf("env");
	else if (strcmp(data.arg[0], "export") == 0)
	 	printf("export");
	else
		printf("command not found: %s\n", data.arg[0]);
}

void	tirnak_kontrol(t_data data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data.b_arg[i])
	{
		if (data.b_arg[i] == '"')
			j++;
		i++;
	}
	if (j % 2 != 0)
		ft_error(data, 0);
	i = 0;
	j = 0;
	while (data.b_arg[i])
	{
		if (data.b_arg[i] == 47)
			j++;
		i++;
	}
	if (j % 2 != 0)
		ft_error(data, 0);
}

void	parse(t_data data)
{
	
	tirnak_kontrol(data);
	ilkarguman(data);
	

	

}
