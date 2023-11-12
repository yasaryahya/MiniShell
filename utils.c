/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:00:19 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/12 02:26:43 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	set_args(t_data *data)
{
	if (data)
	{
		data->arg = NULL;
		data->cmd = NULL;
		data->b_arg = NULL;
		data->cmd_path = NULL;
		data->flag_dollar = 0;
		data->error_no = 0;
		data->flag_token = 0;
		data->pipe_count = 0;
		data->env = NULL;
		data->arguman = NULL;
		data->lexer = NULL;
	}
}

char	*to_lowercase(char *str)
{
	char	*new;

	int (i) = -1;
	if (str == NULL)
		return (NULL);
	new = (char *)malloc(ft_strlen(str) + 1);
	if (new == NULL)
		return (NULL);
	while (str[++i])
		new[i] = ft_tolower(str[i]);
	new[i] = '\0';
	return (new);
}

char	*find_and_clear(char *str, int search1, int search2, t_data *data)
{
	int (i) = -1;
	int (j) = 0;
	char *(new_str) = malloc(ft_strlen(str) + 1);
	if (!new_str)
	{
		ft_error("Malloc Error", 1, data);
	}
	while (str[++i])
	{
		if ((str[i] != search1) && (str[i] != search2))
		{
			new_str[j++] = str[i];
		}
	}
	new_str[j] = '\0';
	return (new_str);
}

int	quotes_control(char *command)
{
	int (quote_number) = 0;
	int (i) = 0;
	int (single_quotes) = 0;
	int (double_quotes) = 0;
	while (command[i])
	{
		if (command[i] == '"' && !single_quotes)
		{
			double_quotes = !double_quotes;
			quote_number++;
		}
		else if (command[i] == '\'' && !double_quotes)
		{
			single_quotes = !single_quotes;
			quote_number++;
		}
		i++;
	}
	if (quote_number % 2 != 0)
		return (0);
	return (1);
}
