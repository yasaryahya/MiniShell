/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:39:35 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/18 07:35:06 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	cd_two(t_data *data, char **cmd, char *home)
{
	char	*str;

	if (ft_strncmp(cmd[1], "~", 1) == 0)
	{
		if (!cmd[1][1])
			str = ft_strjoin(home, "");
		else
		{
			str = ft_strchr(cmd[1], '/');
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
		if (chdir(cmd[1]) != 0)
		{
			ft_error("function/cd: Dizin hatası", 0);
			return ;
		}
	}
}

void	cd(t_data *data, char **cmd)
{
	char	*home;

	home = getenv("HOME");
	if (data->arg_count != 2)
	{
		printf("sss: %d", data->arg_count);
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
	if (ft_strncmp(cmd[1], ".", ft_strlen(cmd[1])) == 0)
		return ;
	else if (ft_strncmp(cmd[1], "..", ft_strlen(cmd[1])) == 0)
	{
		cd_three(data, cmd, home);
		if (chdir("..") != 0)
		{
			ft_error("function/cd: cd hatası", 0);
			return ;
		}
	}
	cd_two(data, cmd, home);
	return ;
}

