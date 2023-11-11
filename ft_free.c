/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:31:35 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/12 00:00:24 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

char	**ft_free_malloc(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	free_data(t_data *data, char *command)
{
	if (data->lexer->full_str && !data->pipe_count)
		free(data->lexer->full_str);
	if (data->lexer && !data->pipe_count)
		free(data->lexer);
	if (data->b_arg)
		free(data->b_arg);
	if (data->arg && !data->pipe_count && !data->flag_token)
		ft_free_malloc(data->arg);
	(void)command;
	if (command)
		free(command);
}
