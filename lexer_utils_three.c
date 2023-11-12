/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:31:42 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/12 17:33:49 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	handle_greater(char *new_str, int i, t_data *data)
{
	if ((new_str[i + 1] == '\n' || new_str[i + 1] == '\0')
		|| ((new_str[i + 1] == '>') && (new_str[i + 2] == '\n'
				|| new_str[i + 2] == '\0')) || ((new_str[i + 2] == '<')
			|| ((new_str[i + 1] == '>') && (new_str[i + 3] == '>'))))
	{
		ft_error("bash: syntax error near unexpected token '>'\n", 127, data);
		data->flag_token = 1;
	}
}

void	handle_less(char *new_str, int i, t_data *data)
{
	if ((new_str[i + 1] == '\n' || new_str[i + 1] == '\0')
		|| ((new_str[i + 1] == '<') && (new_str[i + 2] == '\n'
				|| new_str[i + 2] == '\0')) || ((new_str[i + 2] == '>')
			|| ((new_str[i + 1] == '<') && (new_str[i + 3] == '<'))))
	{
		ft_error("bash: syntax error near unexpected token '<'\n", 127, data);
		data->flag_token = 1;
	}
}

void	handle_pipe(char *new_str, int i, t_data *data)
{
	if ((i == 0) || (ft_strlen(new_str) - 1 == i) || (new_str[i + 1] == '\n'
			|| new_str[i + 1] == '\0') || (new_str[i + 2] == '|'))
	{
		ft_error("bash: syntax error near unexpected token `|'\n", 127, data);
		data->flag_token = 1;
	}
}

int	lexer_error_control(t_data *data)
{
	char *(new_str) = space_single(data);
	int (i) = 0;
	while (new_str[i] && !data->flag_token)
	{
		if (new_str[i] == '>')
		{
			handle_greater(new_str, i, data);
			break ;
		}
		else if (new_str[i] == '<')
		{
			handle_less(new_str, i, data);
			break ;
		}
		else if (new_str[i] == '|')
		{
			handle_pipe(new_str, i, data);
			break ;
		}
		i++;
	}
	free(new_str);
	if (data->flag_token)
		return (0);
	return (1);
}
