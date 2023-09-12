/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:14:22 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/11 18:23:36 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//rl_replace_line("", 0);
#include "../library/minishell.h"

void	ft_sig(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == 3)
		printf("%s", "\n");
	else if (sig == 4)
	{
		printf("\nExit\n");
		exit (0);
	}
}
