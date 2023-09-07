/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 00:55:28 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/08 00:43:58 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	ft_exit(t_data *data)
{
	if (data->arg_count <= 2)
		exit(0);
	else
		ft_error("exit: too many arguments\n", 0);
	return;
}