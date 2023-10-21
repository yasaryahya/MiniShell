/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_slash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:40 by yyasar            #+#    #+#             */
/*   Updated: 2023/10/21 12:15:08 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void	slash(char **cmd, t_data *data)
{
	pid_t	pid;

	data->error_no = 0;
	pid = fork();
	if (pid < 0)
		ft_error("function/bin_ls: Fork Error", 1 , data);
	else if (pid == 0)
	{
		data->error_no = 0;
		execve(cmd[0], cmd, NULL);
		printf("bash: %s:", cmd[0]);
		ft_error(" No such file or directory\n", 127, data);
	}
	else
		wait(NULL);
	return ;
}
