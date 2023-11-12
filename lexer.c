/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:00:12 by sustmas           #+#    #+#             */
/*   Updated: 2023/10/20 20:26:39 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	dollar_token(t_data *data)
{
	char *(str) = ft_strdup("");
	char *(nbr) = ft_itoa(data->error_no);
	if (data->b_arg[data->i] == '?')
	{
		copy_to_str(data->lexer, nbr, data->lexer->full_str);
		data->i++;
	}
	else
	{
		if (!data->b_arg[data->i])
			copy_to_str(data->lexer, "$", data->lexer->full_str);
		else
		{
			while (data->b_arg[data->i] && (ft_isalnum(data->b_arg[data->i])
					|| data->b_arg[data->i] == 95))
			{
				str = ft_strjoin_char(str, data->b_arg[data->i]);
				data->i++;
			}
			if (str)
				find_env_dollar(data, str);
		}
	}
	free(str);
	free(nbr);
}

void	lexer_token_quote_2(t_data *data)
{
	while (data->b_arg[data->i])
	{
		if (data->b_arg[data->i] == '"' && data->lexer->cift_tirnak)
			data->lexer->cift_tirnak = 0;
		else if (data->b_arg[data->i] == '\'' && data->lexer->tek_tirnak)
			data->lexer->tek_tirnak = 0;
		else if (data->lexer->cift_tirnak && data->b_arg[data->i] == '$')
		{
			data->i++;
			dollar_token(data);
			continue ;
		}
		if (!data->lexer->cift_tirnak && !data->lexer->tek_tirnak)
		{
			data->i++;
			break ;
		}
		data->lexer->full_str = ft_strjoin_char(data->lexer->full_str,
				data->b_arg[data->i]);
		data->i++;
	}
}

void	lexer_token_quote(t_data *data)
{
	data->lexer->tek_tirnak = 0;
	data->lexer->cift_tirnak = 0;
	if (data->b_arg[data->i] == '"' && !data->lexer->tek_tirnak)
		data->lexer->cift_tirnak = 1;
	else if (data->b_arg[data->i] == '\'' && !data->lexer->cift_tirnak)
		data->lexer->tek_tirnak = 1;
	data->i++;
	lexer_token_quote_2(data);
}

int	lexer_two(t_data *data, t_lexer *lexer)
{
	char	str[2];

	if (data->b_arg[data->i] == '"' || data->b_arg[data->i] == '\'')
	{
		lexer_token_quote(data);
		return (0);
	}
	else if (data->b_arg[data->i] == '$')
	{
		data->i++;
		dollar_token(data);
		return (0);
	}
	else if (!data->flag)
	{
		str[0] = data->b_arg[data->i];
		str[1] = '\0';
		copy_to_str(lexer, str, lexer->full_str);
	}
	data->i++;
	data->flag = 0;
	return (1);
}

void	lexer(t_data *data)
{
	t_lexer *(lexer) = data->lexer;
	lexer->full_str = ft_strdup("");
	while (data->b_arg[data->i])
	{
		if (data->b_arg[data->i] == '|')
		{
			if (lexer_pipe(data, lexer) == 0)
				break ;
			data->flag = 1;
		}
		else if (data->b_arg[data->i] == '<')
		{
			if (lexer_input(data, lexer) == 0)
				break ;
			data->flag = 1;
		}
		else if (data->b_arg[data->i] == '>')
		{
			if (lexer_output(data, lexer) == 0)
				break ;
			data->flag = 1;
		}
		if (lexer_two(data, lexer) == 0)
			continue ;
	}
}
