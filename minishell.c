/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/08/31 18:15:09 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	minishell(void)
{
	char *command;
	t_data data;

  	while (1)
  	{
		signal(SIGINT, ft_sig);
		signal(SIGQUIT, ft_sig);
		command = readline("\033[31msalihshell$\033[0m ");
  		add_history(command);
		data.len = ft_strlen(command);
		data.b_arg = command;
		data.arg = ft_split(command, ' ');
		int i = 0;
		int j = 0;
		while (data.arg[i])
		{
			j = 0;
			while (data.arg[i][j])
			{
				if (data.arg[i][j] == '<' || data.arg[i][j] == '>')
					buyukkucuk(data, i, j);
				else if (data.arg[i][j] == '"')
					cifttirnak(data, i, j);
				j++;
			}
			i++;
		}		
  	}	
}


int main(void)
{
	minishell();
	return 0;
}
