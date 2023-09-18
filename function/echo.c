/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:22:08 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/18 03:39:54 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
#include <stdbool.h>

void	ft_echo(char **cmd)
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

	if(ft_strncmp(cmd[1], "-n", 2) == 0)
		i++;
	while(cmd[i])
	{	
		j = 0;
		while (cmd[i][j])
		{
			if(cmd[i][j] == '"' && !tek_tirnak && flag)
			{
				cift_tirnak = 1;
				flag = 0;
				j++;
			}
			else if(cmd[i][j] == '\'' && !cift_tirnak && flag) 
			{
				tek_tirnak = 1;
				flag = 0;
				j++;
			}
			else if(cmd[i][j] == '"' && cift_tirnak)
			{
				cift_tirnak = 0;
				flag = 1;
				j++;
			}
			else if(cmd[i][j] == '\'' && tek_tirnak)
			{
				tek_tirnak = 0;
				flag = 1;
				j++;
			}
			else
			{	
				write(1, &cmd[i][j], 1);
				j++;
			}
		}
		write(1, " ", 1);
		i++;
	}
	printf("\n");
}
