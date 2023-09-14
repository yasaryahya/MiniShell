/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:40 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/14 23:35:43 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void	bin_ls(void) 
{
    pid_t pid = fork();

    if (pid < 0)
        ft_error("function/bin_ls: fork hatası", 1);
	else if (pid == 0)
	{
        // Çocuk işlem
        char *komut = "/bin/ls"; // /bin dizinindeki ls komutu
        char *args[] = {komut, "/bin", NULL}; //hedef dizin

        // Yeni komutu çalıştır
        execve(komut, args, NULL);

        // execve başarısızsa aşağıdaki kod çalışır
        ft_error("function/bin_ls: execve hatası", 1);
    }
	else
        // Ebeveyn işlem
        wait(NULL); // Çocuk işleminin bitmesini bekler
    return;
}
