/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 06:51:25 by sustmas           #+#    #+#             */
/*   Updated: 2023/10/21 10:36:35 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
void	lexer_token_pipe(t_data *data)
{
	char	*str;

	str = NULL;
	if (data->b_arg[data->i] == '|')
	{
		data->pipe_count++;
		str = ft_strdup(" | ");
	}
	data->lexer->full_str = ft_strjoin(data->lexer->full_str, str);
	free(str);
}

void	lexer_token_input(t_data *data)
{
	char	*str;

	str = NULL;
	if (data->b_arg[data->i] == '>')
	{
		if (data->b_arg[data->i + 1] == '>')
		{
			str = ft_strdup(" >> ");
			data->i++;
		}
		else
			str = ft_strdup(" > ");
	}
	data->lexer->full_str = ft_strjoin(data->lexer->full_str, str);
	free(str);
}

void	lexer_token_output(t_data *data)
{
	char	*str;

	str = NULL;
	if (data->b_arg[data->i] == '<')
	{
		if (data->b_arg[data->i + 1] == '<')
		{
			str = ft_strdup(" << ");
			data->i++;
		}
		else
			str = ft_strdup(" < ");
	}
	data->lexer->full_str = ft_strjoin(data->lexer->full_str, str);
	free(str);
}
*/