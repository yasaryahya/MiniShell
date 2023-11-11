/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:52:26 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/11 22:52:26 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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

int	ft_echo_two(char **cmd, t_data *data, int *flag, int *i)
{
	data->error_no = 0;
	if (!cmd[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ft_strcmp(cmd[1], "-n") == 0)
	{
		(*i)++;
		*flag = 0;
	}
	return (1);
}

int	ft_echo(char **cmd, int i, t_data *data)
{
	char (quote_type) = '\0';
	int (flag) = 1;
	if (ft_echo_two(cmd, data, &flag, &i) == 0)
		return (0);
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
	return (0);
}
