/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_slash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:40 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/11 22:21:41 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	slash(char **cmd, t_data *data)
{
	pid_t	pid;

	data->error_no = 0;
	pid = fork();
	if (pid < 0)
		ft_error("function/bin_ls: Fork Error", 1, data);
	else if (pid == 0)
	{
		data->error_no = 0;
		execve(cmd[0], cmd, NULL);
		printf("bash: %s:", cmd[0]);
		ft_error(" No such file or directory\n", 127, data);
		exit (1);
	}
	else
		wait(NULL);
	return ;
}
