/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:22:08 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/13 05:55:46 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../library/minishell.h"

void	lexer_utils(t_data *data)
{
	int		flag;
	int		i;
	int		j;
	char	*str;

	data->lexer->tek_tirnak = 0;
	data->lexer->cift_tirnak = 0;
	flag = 1;
	j = 1;
	i = data->lexer->index;

	str = ft_strdup(" ");
	while(data->b_arg[i])
	{	
			if(data->b_arg[i] == '"' && !data->lexer->tek_tirnak && flag)
			{
				data->lexer->cift_tirnak = 1;
				flag = 0;
			}
			else if(data->b_arg[i] == '\'' && !data->lexer->cift_tirnak && flag) 
			{
				data->lexer->tek_tirnak = 1;
				flag = 0;			
			}
			else if(data->b_arg[i] == '"' && data->lexer->cift_tirnak)
			{
				data->lexer->cift_tirnak = 0;
				flag = 1;
				break;				
			}
			else if(data->b_arg[i] == '\'' && data->lexer->tek_tirnak)
			{
				data->lexer->tek_tirnak = 0;
				flag = 1;
				break;			
			}
			str[j] = data->b_arg[i];
		i++;
		j++;
	}
	str[j++] = data->b_arg[i++];
	str[j++] = ' ';
	str[j] = '\0';
	data->lexer->full_str = ft_strjoin(data->lexer->full_str, str);
	data->lexer->index = i;
}*/