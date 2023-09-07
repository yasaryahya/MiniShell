/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:22:08 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/08 00:43:10 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <stdbool.h>

void	ft_echo(t_data *data)
{
	int		tek_tirnak;
	int		cift_tirnak;
	int		flag;
	int		i;
	int 	j;

	tek_tirnak = 0;
	cift_tirnak = 0;
	flag = 1;
	i = 1;

	while(data->arg[i])
	{	
		j = 0;
		while (data->arg[i][j])
		{
			if(data->arg[i][j] == '"' && !tek_tirnak && flag)
			{
				cift_tirnak = 1;
				flag = 0;
				j++;
			}
			else if(data->arg[i][j] == '\'' && !cift_tirnak && flag) 
			{
				tek_tirnak = 1;
				flag = 0;
				j++;
			}
			else if(data->arg[i][j] == '"' && cift_tirnak)
			{
				cift_tirnak = 0;
				flag = 1;
				j++;
			}
			else if(data->arg[i][j] == '\'' && tek_tirnak)
			{
				tek_tirnak = 0;
				flag = 1;
				j++;
			}
			else
			{	
				write(1, &data->arg[i][j], 1);
				j++;
			}
		}
		i++;
		printf(" ");
	}
	printf("\n");
}
