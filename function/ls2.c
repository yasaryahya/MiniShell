/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:08:34 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/06 00:24:18 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

void	ls_l()
{
	pid_t pid = fork();

    if (pid < 0)
        ft_error("function/ls2: Fork hatası", 1);
    else if (pid == 0)
	{
        char *komut = "/bin/ls";
        char *args[] = {komut, "-l", NULL};

        execve(komut, args, NULL);
        ft_error("function/ls2: execve hatası", 1);
    }
	else
    	 wait(NULL);
	return;
}

void	ls_a()
{
	pid_t pid = fork();

    if (pid < 0)
        ft_error("function/ls2: Fork hatası", 1);
    else if (pid == 0)
	{
        char *komut = "/bin/ls";
        char *args[] = {komut, "-a", NULL};

        execve(komut, args, NULL);
        ft_error("function/ls2: execve hatası", 1);
    }
	else
    	 wait(NULL);
	return;
}