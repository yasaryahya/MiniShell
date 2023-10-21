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

#include "../minishell.h"
#include <stdlib.h>

void	copy_to_str_and_concat(t_lexer *lexer, char *str, char *full_str)
{
	size_t	str_len;
	size_t	full_str_len;
	char	*new_full_str;

	str_len = ft_strlen(str);
	full_str_len = ft_strlen(full_str);
	new_full_str = (char *)malloc(str_len + full_str_len + 1);
	if (new_full_str)
	{
		//printfe eklenecek
		strcpy(new_full_str, full_str);
		ft_strcat(new_full_str, str);
		free(full_str);
		lexer->full_str = new_full_str;
	}
}

void	find_env_dollar(t_data *data, char *str)
{
	t_env		*(tmp) = data->env;
	t_arguman	*(arg_tmp) = data->arguman;
	t_lexer		*(lexer) = data->lexer;
	int			(flag) = 0;

	data->a = 0;
	while(tmp)
	{
		if (ft_strcmp(tmp->first, str) == 0)
		{
			data->a = 1;
			flag = 1;
			data->flag_dollar = 1;
			break ;
		}
		tmp = tmp->next;
	}
	while (arg_tmp && !flag)
	{
		if (ft_strcmp(arg_tmp->first, str) == 0)
		{
			data->a = 2;
			data->flag_dollar = 1;
			break ;
		}
		arg_tmp = arg_tmp->next;
	}
	if (data->a == 1)
		copy_to_str_and_concat(lexer, tmp->second, lexer->full_str);
	else if (data->a == 2)
		copy_to_str_and_concat(lexer, arg_tmp->second, lexer->full_str);
	else
		copy_to_str_and_concat(lexer, "	", lexer->full_str);
}

void	dollar_token(t_data *data)
{
	char	*str;
	char	*(nbr) =ft_itoa(data->error_no);

	data->i++;
	if (data->b_arg[data->i] == '?')
		copy_to_str_and_concat(data->lexer, nbr, data->lexer->full_str);
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
	free(nbr);
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

void	lexer(t_data *data)
{
	t_lexer	*lexer;
	char	str[2];

	lexer = data->lexer;
	data->i = 0;
	lexer->full_str = ft_strdup("");
	while (data->b_arg[data->i] != '\0')
	{
		if (data->b_arg[data->i] == '\\' || data->b_arg[data->i] == ';')
			copy_to_str_and_concat(lexer, " ", lexer->full_str);
		else if (data->b_arg[data->i] == '|')
		{
			data->pipe_count++;
			copy_to_str_and_concat(lexer, " | ", lexer->full_str);
		}
		else if (data->b_arg[data->i] == '<')
		{
			if (data->b_arg[data->i + 1] == '<')
				copy_to_str_and_concat(lexer, " << ", lexer->full_str);
			else
				copy_to_str_and_concat(lexer, " < ", lexer->full_str);
		}
		else if (data->b_arg[data->i] == '>')
		{
			if (data->b_arg[data->i + 1] == '<')
				copy_to_str_and_concat(lexer, " >> ", lexer->full_str);
			else
				copy_to_str_and_concat(lexer, " > ", lexer->full_str);
		}
		else if (data->b_arg[data->i] == '"' || data->b_arg[data->i] == '\'')
			lexer_token_quote(data);
		else if (data->b_arg[data->i] == '$')
			dollar_token(data);
		else
		{
			str[0] = data->b_arg[data->i];
			str[1] = '\0';
			copy_to_str_and_concat(lexer, str, lexer->full_str);
		}
		data->i++;
	}
}
