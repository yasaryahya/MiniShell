/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:38:35 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/05 18:50:15 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	ft_error(char *str, int flag)
{
	if (flag == 1)
	{
		printf("%s", str);
		exit(EXIT_FAILURE);
	}
	else
		printf("%s", str);
	return;
}
