/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:39:35 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/19 06:45:31 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
// str free yap!!

void	cd_two(t_data *data, char *home)
{
	char	*str;

	if (ft_strncmp(data->arg[1], "~", 1) == 0)
	{
		if (!data->arg[1][1])
			str = ft_strjoin(home, "");
		else
		{
			str = ft_strchr(data->arg[1], '/');
			str = ft_strjoin(home, str);
		}
		if (chdir(str) != 0)
		{
			ft_error("function/cd: cd hatası", 0);
			return ;
		}
	}
	else
	{
		if (chdir(data->arg[1]) != 0)
		{
			ft_error("function/cd: Dizin hatası", 0);
			return ;
		}
	}
}

void	cd(t_data *data)
{
	char	*home;

	home = getenv("HOME");
	if (data->arg_count != 2)
	{
		if (data->arg_count == 1)
		{
			if (home == NULL)
				ft_error("function/cd: HOME ortam değişkeni ayarlanmamış", 1);
			if (chdir(home) != 0)
				ft_error("function/cd:", 1);
		}
		else
			ft_error("Kullanım: cd <dizin>\n", 0);
		return ;
	}
	if (ft_strncmp(data->arg[1], ".", ft_strlen(data->arg[1])) == 0)
		return ;
	if (ft_strncmp(data->arg[1], "..", ft_strlen(data->arg[1])) == 0)
	{
		if (chdir("..") != 0)
		{
			ft_error("function/cd: cd hatası", 0);
			return ;
		}
		return;		
	}
	cd_two(data, home);
	return ;
}
