/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:04:53 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/15 03:53:57 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

/*
int	pipe_control(t_data *data)
{
	char	**pipe_str = NULL;

	if (data->pipe_count >= 1)
	{
		pipe_str = (char **)malloc(sizeof(char *)* data->pipe_count + 2);
		if (!pipe_str)
			ft_error("pipe_token/ malloc error", 1);
		int i = 0;
		int j = 0;
		int k = 0;
		while (data->lexer->full_str[i])
		{
			if (k == 0)
				pipe_str[j] = (char *)malloc(sizeof(char) * 100);
			if (data->lexer->full_str[i] == '|')
			{
				pipe_str[j++][k] = '\0';
				k = 0;
			}
			pipe_str[j][k++] = data->lexer->full_str[i++];
		}
		i = 0;
		j = 0;
		while (pipe_str[i])
			printf("pipe_str%d: %s", j++, pipe_str[i++]);
		return(1);
	}
	else
		return (0);
}
*/