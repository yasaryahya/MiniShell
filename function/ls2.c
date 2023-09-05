/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:08:34 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/05 22:43:39 by yyasar           ###   ########.fr       */
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
        // Çocuk işlem
        char *komut = "/bin/ls"; // /bin dizinindeki ls komutu
        char *args[] = {komut, "-l", NULL}; // ls -l komutu

        // Yeni komutu çalıştır
        execve(komut, args, NULL);

        // execve başarısızsa aşağıdaki kod çalışır
        ft_error("function/ls2: execve hatası", 1);
    }
	else // Ebeveyn işlem
    	 wait(NULL); // Çocuk işleminin bitmesini bekler
	return;
}