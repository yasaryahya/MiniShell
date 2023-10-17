/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_bin_ls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:40 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/22 03:36:01 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void	slash(char **cmd, t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_error("function/bin_ls: fork hatası", 1 , data);
	else if (pid == 0)
	{
		execve(cmd[0], cmd, NULL);
		ft_error("function/bin_ls: execve hatası\n", 1, data);
	}
	else
		wait(NULL);
	return ;
}
