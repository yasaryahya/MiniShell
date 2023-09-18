/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:40 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/18 07:32:44 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void	bin_ls(void)
{
	pid_t	pid;
	char	*komut;
	char	**args;

	pid = fork();
	if (pid < 0)
		ft_error("function/bin_ls: fork hatası", 1);
	else if (pid == 0)
	{
		komut = "/bin/ls";
		args[3] = {komut, "/bin", NULL};
		execve(komut, args, NULL);
		ft_error("function/bin_ls: execve hatası", 1);
	}
	else
		wait(NULL);
	return ;
}
