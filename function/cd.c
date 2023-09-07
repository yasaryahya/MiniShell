/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:39:35 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/06 22:01:46 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	cd(t_data data)
{
    if (data.arg_count != 2)
	{
        ft_error("Kullanım: cd <dizin>\n", 0);
        return;
    }
    if (ft_strncmp(data.arg[1], ".", ft_strlen(data.arg[1])) == 0)
        return;
    else if (ft_strncmp(data.arg[1], "..", ft_strlen(data.arg[1])) == 0)
	{	// "cd .." komutunu ele alın
        if (chdir("..") != 0)
		{
            ft_error("function/cd: cd hatası", 0);
            return;
        }
    }
	else
	{	// Diğer "cd dizin" komutlarını ele alın
        if (chdir(data.arg[1]) != 0)
		{
            ft_error("function/cd: Dizin hatası", 0);
            return;
        }
    }
    return;
}
