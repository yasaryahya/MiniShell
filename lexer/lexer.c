/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:00:12 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/21 10:06:03 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

void	lexer(t_data *data)
{
	data->i = 0;
	data->lexer->full_str = strdup("");
	while (data->b_arg[data->i])
	{
		if (data->b_arg[data->i] == '\\' || data->b_arg[data->i] == ';')
			data->lexer->full_str = ft_strjoin_char(data->lexer->full_str, ' ');
		else if (data->b_arg[data->i] == '|')
			lexer_token_pipe(data);
		else if (data->b_arg[data->i] == '>')
			lexer_token_input(data);
		else if (data->b_arg[data->i] == '<')
			lexer_token_output(data);
		else if (data->b_arg[data->i] == '$')
		{
			data->i++;
			dollar_token(data);
		}
		else if (data->b_arg[data->i]
			== '"' || data->b_arg[data->i] == '\'')
			lexer_token_quote(data);
		else
			data->lexer->full_str = ft_strjoin_char(data->lexer->full_str,
					data->b_arg[data->i]);
		data->i++;
	}
}
