/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/14 22:16:31 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	dollar_token(t_data *data)
{
	char *str;
	int i;
	char *str_2;
	
	str = ft_strdup("");
	str_2 = ft_strdup("");
	i = data->lexer->index;
	while(data->b_arg[i] && (ft_isalnum(data->b_arg[i]) || data->b_arg[i] == 95))
	{
		str = ft_strjoin_char(str, data->b_arg[i]);
		i++;
	}
	int j = ft_check_strdup(data, str, 0, 0);
	if(j > 0)
	{
		int x = ft_strlen(str) + 1;
		int a = 0;
		while (data->envrt[j][x])
		{
			str_2 = ft_strjoin_char(str_2,data->envrt[j][x]);
			a++;
			x++;
		}
	}
	
	data->lexer->full_str = ft_strjoin(data->lexer->full_str, str_2);
	data->lexer->index = i;
	free(str);
	free(str_2);
}