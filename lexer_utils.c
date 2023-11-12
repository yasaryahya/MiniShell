/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:29:13 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/12 16:23:37 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	find_env_two(t_env *tmp, char *str, t_data *data, int *flag)
{
	while (tmp)
	{
		if (ft_strcmp(tmp->first, str) == 0)
		{
			data->a = 1;
			*flag = 1;
			data->flag_dollar = 1;
			if (data->a == 1)
				copy_to_str(data->lexer, tmp->second, data->lexer->full_str);
			break ;
		}
		tmp = tmp->next;
	}
}

void	find_env_dollar(t_data *data, char *str)
{
	t_env *(tmp) = data->env;
	t_arguman *(arg_tmp) = data->arguman;
	t_lexer *(lexer) = data->lexer;
	int (flag) = 0;
	data->a = 0;
	find_env_two(tmp, str, data, &flag);
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
	if (data->a == 2)
		copy_to_str(lexer, arg_tmp->second, lexer->full_str);
	else
		copy_to_str(lexer, "", lexer->full_str);
}

int	lexer_input(t_data *data, t_lexer *lexer)
{
	if (data->b_arg[data->i + 1] == '<')
	{
		copy_to_str(lexer, " << ", lexer->full_str);
		data->i++;
	}
	else
		copy_to_str(lexer, " < ", lexer->full_str);
	data->token++;
	return (1);
}

int	lexer_output(t_data *data, t_lexer *lexer)
{
	if (data->b_arg[data->i + 1] == '>')
	{
		copy_to_str(lexer, " >> ", lexer->full_str);
		data->i++;
	}
	else
		copy_to_str(lexer, " > ", lexer->full_str);
	data->token++;
	return (1);
}

int	lexer_pipe(t_data *data, t_lexer *lexer)
{
	data->pipe_count++;
	copy_to_str(lexer, " | ", lexer->full_str);
	return (1);
}
