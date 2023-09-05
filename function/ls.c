/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:58:20 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/06 02:11:15 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

void ls()
{
    DIR *dp;
    struct dirent *ep;
    int i;

    // Mevcut dizini aç
    dp = opendir("./");
    if (dp != NULL)
	{
        i = 1;
        // Dizin içindeki dosyaları listele
        while ((ep = readdir(dp)))
		{
            if (i % 5 == 0)
                printf("%s\n", ep->d_name);
            if (ep->d_name[0] != '.')
            {
                printf("%s   	", ep->d_name);
                i++;
            }
        }
        (void)closedir(dp);
    }
	else
		ft_error("function/ls: Dizin(ls) açma hatası", 1);
    printf("\n");
    return;
}

void	ls_la(void)
{
	pid_t pid = fork();

    if (pid < 0)
        ft_error("function/ls: Fork hatası", 1);
    else if (pid == 0)
	{	// Çocuk işlem
        char *komut = "/bin/ls"; // /bin dizinindeki ls komutu
        char *args[] = {komut, "-la", NULL}; // ls -la komutu

        // Yeni komutu çalıştır
        execve(komut, args, NULL);

        // execve başarısızsa aşağıdaki kod çalışır
        ft_error("function/ls: execve hatası", 1);
    }
	else // Ebeveyn işlem
    	wait(NULL); // Çocuk işleminin bitmesini bekler
    return;
}

void	ls_genel(t_data data)
{
	if (!data.arg[1])
		ls();
	else if (ft_strncmp(data.arg[1], "-l", ft_strlen(data.arg[1])) == 0)
		ls_l();
	else if (ft_strncmp(data.arg[1], "-a", ft_strlen(data.arg[1])) == 0)
		ls_a();
	else if (ft_strncmp(data.arg[1], "-la", ft_strlen(data.arg[1])) == 0)
		ls_la();
	else
	{
		printf("%s %s ", "ls", data.arg[1]);
		ft_error("function/ls: No such file or directory\n", 0);
	}	
	return;
}