/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_bin_ls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:40 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/21 06:25:11 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void	bin_ls(char **cmd, t_data *data)
{
	pid_t	pid;
	char	*komut;
	char	**args;

	if (cmd[1])
	{
		printf("ls: %s: No such file or directory\n", cmd[1]);
		return ;
	}
	pid = fork();
	if (pid < 0)
		ft_error("function/bin_ls: fork hatası", 1 , data);
	else if (pid == 0)
	{
		komut = "/bin/ls";
		args = (char *[]){komut, "/bin", NULL};
		execve(komut, args, NULL);
		ft_error("function/bin_ls: execve hatası", 1, data);
	}
	else
		wait(NULL);
	return ;
}
