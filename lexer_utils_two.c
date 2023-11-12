/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:01:56 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/12 16:50:07 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	copy_to_str(t_lexer *lexer, char *str, char *full_str)
{
	size_t	str_len;
	size_t	full_str_len;
	char	*new_full_str;

	str_len = ft_strlen(str);
	full_str_len = ft_strlen(full_str);
	new_full_str = (char *)malloc(str_len + full_str_len + 1);
	if (new_full_str)
	{
		ft_strcpy(new_full_str, full_str);
		ft_strcat(new_full_str, str);
		free(full_str);
		lexer->full_str = new_full_str;
	}
}

char	*space_single(t_data *data)
{
	int (i) = 0;
	int (flag) = 0;
	char *(str) = ft_strdup("");
	while (data->lexer->full_str[i] == ' ' || data->lexer->full_str[i] == '\t')
		i++;
	while (data->lexer->full_str[i])
	{
		if (data->lexer->full_str[i] == ' '
			|| data->lexer->full_str[i] == '\t')
			flag = 1;
		if (!(data->lexer->full_str[i] == ' '
				|| data->lexer->full_str[i] == '\t'))
		{
			if (flag)
				str = ft_strjoin_char(str, ' ');
			flag = 0;
			str = ft_strjoin_char(str, data->lexer->full_str[i]);
		}
		i++;
	}
	return (str);
}
/*
void	lexer_error_control(t_data *data)
{
	char	*new_str;

	int (i) = 0;
	new_str = space_single(data);
	while (new_str[i])
	{
		if (new_str[i] == '>')
		{
			if (new_str[i + 1] == '\n' || new_str[i + 1] == '\0')
			{
				ft_error("syntax error near unexpected token `\\n'\n", 127,
					data);
				data->flag_token = 1;
				break ;
			}
			else if ((new_str[i + 1] == '>') && (new_str[i + 2] == '\n'
					|| new_str[i + 2] == '\0'))
			{
				ft_error("syntax error near unexpected token `\\n'\n", 127,
					data);
				data->flag_token = 1;
				break ;
			}
			else if (new_str[i + 2] == '<')
			{
				ft_error("syntax error near unexpected token `<'\n", 127, data);
				data->flag_token = 1;
				break ;
			}
			else if ((new_str[i + 1] == '>') && (new_str[i + 3] == '>'))
			{
				ft_error("syntax error near unexpected token `>'\n", 127, data);
				data->flag_token = 1;
				break ;
			}
		}
		else if (new_str[i] == '<')
		{
			if (new_str[i + 1] == '\n' || new_str[i + 1] == '\0')
			{
				ft_error("syntax error near unexpected token `\\n'\n", 127,
					data);
				data->flag_token = 1;
				break ;
			}
			else if ((new_str[i + 1] == '<')
				&& (new_str[i + 2] == '\n' || new_str[i + 2] == '\0'))
			{
				ft_error("syntax error near unexpected token `\\n'\n", 127,
					data);
				data->flag_token = 1;
				break ;
			}
			else if (new_str[i + 2] == '>')
			{
				ft_error("syntax error near unexpected token `>'\n", 127, data);
				data->flag_token = 1;
				break ;
			}
			else if ((new_str[i + 1] == '<') && (new_str[i + 3] == '<'))
			{
				ft_error("syntax error near unexpected token `<'\n", 127, data);
				data->flag_token = 1;
				break ;
			}
		}
		else if (new_str[i] == '|')
		{
			if ((i == 0) || (ft_strlen(new_str) - 1 == i))
			{
				ft_error("syntax error near unexpected token `|'\n", 127, data);
				data->flag_token = 1;
				break ;
			}
			else if (new_str[i + 1] == '\n' || new_str[i + 1] == '\0')
			{
				ft_error("syntax error unexpected token `\\n'\n", 127, data);
				data->flag_token = 1;
				break ;
			}
			else if (new_str[i + 2] == '|')
			{
				ft_error("syntax error near unexpected token `|'\n", 127, data);
				data->flag_token = 1;
				break ;
			}
		}
		i++;
	}
	free(new_str);
}
*/
