/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:00:12 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/22 06:53:37 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdlib.h>

void	lexer(t_data *data)
{
	int	i;
	char	c;
	t_lexer	*lexer;

	lexer = data->lexer;
	i = 0;
	lexer->full_str = strdup("");
	while (data->b_arg[i] != '\0')
	{
		c = data->b_arg[i];
		if (c == '\\' || c == ';')
			lexer->full_str = ft_strjoin_char(lexer->full_str, ' ');
		else if (c == '|'){
			data->pipe_count++;
			lexer->full_str = ft_strjoin(lexer->full_str, " | ");
		}
		else if (c == '<')
			lexer->full_str = ft_strjoin(lexer->full_str, " < ");
		else if (c == '>')
			lexer->full_str = ft_strjoin(lexer->full_str, " > ");
		else if (c == '"' || c == '\'')
			lexer_token_quote(data);
		else
			lexer->full_str = ft_strjoin_char(lexer->full_str, c);
		i++;
	}
}
