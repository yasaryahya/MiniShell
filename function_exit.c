/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:46:41 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/21 21:51:54 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_data *data)
{
	if (data->cmd_count == 1)
		exit(0);
	else
		ft_error("exit: too many arguments\n", 2, data);
	return ;
}
