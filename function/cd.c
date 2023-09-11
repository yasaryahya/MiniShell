/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:39:35 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/11 05:08:05 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	cd(t_data *data)
{
    char *home;
    home = getenv("HOME");

    if (data->arg_count != 2)
	{
        if (data->arg_count == 1)
        {
    
        if (home == NULL)
        {
            ft_error("function/cd: HOME ortam değişkeni ayarlanmamış", 1);
            return;
        }
    
        if (chdir(home) != 0)
        {
            perror("function/cd");
            return;
        }
        }
        else
            ft_error("Kullanım: cd <dizin>\n", 0);
        return;
    }
    if (ft_strncmp(data->arg[1], ".", ft_strlen(data->arg[1])) == 0)
        return;
    else if (ft_strncmp(data->arg[1], "..", ft_strlen(data->arg[1])) == 0)
	{	// "cd .." komutunu ele alın"
        if (chdir("..") != 0)
		{
            ft_error("function/cd: cd hatası", 0);
            return;
        }
    }
    else if(ft_strncmp(data->arg[1], "~", 1) == 0)
    {
        char *str;
        if(!data->arg[1][1])
            str = ft_strjoin(home, "");
        else{
            
            str = ft_strchr(data->arg[1], '/');
            str = ft_strjoin(home, str);
        }
        if (chdir(str) != 0)
		{
            ft_error("function/cd: cd hatası", 0);
            return;
        }
    }
        
        
	else
	{	// Diğer "cd dizin" komutlarını ele alın
        if (chdir(data->arg[1]) != 0)
		{
            ft_error("function/cd: Dizin hatası", 0);
            return;
        }
    }
    return;
}

