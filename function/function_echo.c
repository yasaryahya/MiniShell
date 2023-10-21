/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 21:52:24 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/21 08:33:29 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void	ft_print_quoted_string(char *str, char quote_type)
{
	int (i) = 0;
	while (str[i])
	{
		if (str[i] == quote_type)
		{
			i++;
			while (str[i] && str[i] != quote_type)
			{
				write(1, &str[i], 1);
				i++;
			}
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_echo(char **cmd, int i, t_data *data)
{
	char (quote_type) = '\0';
	bool (flag) = true;
	data->error_no = 0;
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		i++;
		flag = false;
	}
	while (cmd[i])
	{
		if (cmd[i][0] == '"' || cmd[i][0] == '\'')
		{
			quote_type = cmd[i][0];
			ft_print_quoted_string(&cmd[i][1], quote_type);
		}
		else
			write(1, cmd[i], ft_strlen(cmd[i]));

		i++;

		if (cmd[i])
			write(1, " ", 1);
	}
	if (flag)
		write(1, "\n", 1);
}
