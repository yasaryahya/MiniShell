/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:40 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/19 06:20:24 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void	bin_ls(t_data *data)
{
	pid_t	pid;
	char	*komut;
	char	**args;

	if (data->arg[1])
	{
		printf("ls: %s: No such file or directory\n", data->arg[1]);
		return ;
	}
	pid = fork();
	if (pid < 0)
		ft_error("function/bin_ls: fork hatası", 1);
	else if (pid == 0)
	{
		komut = "/bin/ls";
		args = (char *[]){komut, "/bin", NULL};
		execve(komut, args, NULL);
		ft_error("function/bin_ls: execve hatası", 1);
	}
	else
		wait(NULL);
	return ;
}
