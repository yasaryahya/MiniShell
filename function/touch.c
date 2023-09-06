/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 02:46:35 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/06 02:54:52 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>

void touch(t_data data) 
{
    int fd;
	struct stat st;
    // Dosyanın varlığını kontrol et
    if (access(data.arg[1], F_OK) == 0) 
	{
        // Dosya mevcut, son değiştirme zamanını güncelle
        if (utime(data.arg[1], NULL) != 0) {
            ft_error("touch: utime", 0);
        }
    } 
	else 
	{
        // Dosya mevcut değil, yeni bir dosya oluştur
        fd = open(data.arg[1], O_CREAT | O_WRONLY, 0644);
        if (fd == -1) {
            ft_error("touch: open\n", 0);
            return;
        }
        close(fd);
    }

	 if (stat(data.arg[1], &st) != 0) {
        ft_error("touch: stat", 0);
        return;
    }
}