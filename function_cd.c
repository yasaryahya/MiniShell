/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 05:05:07 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/12 01:25:23 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>

void	cd_two(char *home, char **command, t_data *data)
{
	char	*str;

	str = NULL;
	if (ft_strncmp(command[1], "..", ft_strlen(command[1])) == 0)
	{
		if (chdir("..") != 0)
		{
			ft_error("cd: no such file or directory:", 2, data);
			return ;
		}
		return ;
	}
	cd_three(home, command, str, data);
	return ;
}

void	cd_three(char *home, char **command, char *str, t_data *data)
{
	if (ft_strncmp(command[1], "~", 1) == 0)
	{
		if (!command[1][1])
			str = ft_strjoin(home, "");
		else
		{
			str = ft_strchr(command[1], '/');
			str = ft_strjoin(home, str);
		}
		if (chdir(str) != 0)
		{
			ft_error("cd: no such file or directory:\n", 2, data);
			return ;
		}
	}
	else
	{
		if (chdir(command[1]) != 0)
		{
			ft_error("cd: no such file or directory:\n", 2, data);
			return ;
		}
	}
	free(str);
}

void	ft_cd(char **command, t_data *data)
{
	data->error_no = 0;
	if (data->cmd_count != 2)
	{
		if (data->cmd_count == 1)
		{
			if (getenv("HOME") == NULL)
				ft_error("function/cd: HOME environment variable not set", 1,
					data);
			if (chdir(getenv("HOME")) != 0)
				ft_error("function/cd:", 1, data);
		}
		else
			ft_error("Kullanım: cd <dizin>\n", 2, data);
		return ;
	}
	if (ft_strncmp(command[1], ".", ft_strlen(command[1])) == 0)
		return ;
	cd_two(getenv("HOME"), command, data);
	return ;
}
