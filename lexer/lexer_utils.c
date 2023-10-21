/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 06:49:02 by sustmas           #+#    #+#             */
/*   Updated: 2023/10/20 21:29:17 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../minishell.h"

void	find_env_dollar(t_data *data, char *str)
{
	t_arguman	*tmp;
	char		*string;

	tmp = data->arguman;
	string = NULL;
	while (tmp)
	{
		if (ft_strcmp(tmp->first, str) == 0)
		{
			string = ft_strjoin(tmp->second, "");
			data->flag_dollar = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (string)
		data->lexer->full_str = ft_strjoin(data->lexer->full_str, string);
	else
		data->lexer->full_str = ft_strjoin(data->lexer->full_str, str);
	free(string);
}

void	dollar_token(t_data *data)
{
	char	*str;

	if (data->b_arg[data->i] == '?')
		data->lexer->full_str
			=ft_strjoin_char(data->lexer->full_str, data->b_arg[data->i]);
	else
	{
		str = ft_strdup("");
		while (data->b_arg[data->i]
			&& (ft_isalnum(data->b_arg[data->i])
				|| data->b_arg[data->i] == 95))
		{
			str = ft_strjoin_char(str, data->b_arg[data->i]);
			data->i++;
		}
		find_env_dollar(data, str);
		free(str);
	}
}

void	lexer_token_quote_2(t_data *data)
{
	while (data->b_arg[data->i])
	{
		if (data->b_arg[data->i] == '"' && data->lexer->cift_tirnak)
		{
			data->lexer->cift_tirnak = 0;
		}
		else if (data->b_arg[data->i] == '\'' && data->lexer->tek_tirnak)
		{
			data->lexer->tek_tirnak = 0;
		}
		else if (data->lexer->cift_tirnak && data->b_arg[data->i] == '$')
		{
			data->i++;
			dollar_token(data);
		}
		if (!data->lexer->cift_tirnak && !data->lexer->tek_tirnak)
			break ;
		data->lexer->full_str = ft_strjoin_char(data->lexer->full_str,
				data->b_arg[data->i]);
		data->i++;
	}
	data->lexer->full_str
		=ft_strjoin_char(data->lexer->full_str, data->b_arg[data->i]);
}

void	lexer_token_quote(t_data *data)
{
	int	x;
	int	j;

	data->lexer->tek_tirnak = 0;
	data->lexer->cift_tirnak = 0;
	x = data->lexer->tek_tirnak;
	j = data->lexer->cift_tirnak;
	if (data->b_arg[data->i] == '"' && !x)
		data->lexer->cift_tirnak = 1;
	else if (data->b_arg[data->i] == '\'' && !j)
		data->lexer->tek_tirnak = 1;
	data->lexer->full_str
		=ft_strjoin_char(data->lexer->full_str, data->b_arg[data->i]);
	data->i++;
	lexer_token_quote_2(data);
}
*/