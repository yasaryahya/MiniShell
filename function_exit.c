/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:46:41 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/11 22:25:07 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_exit(t_data *data, char *command)
{
	data->error_no = 0;
	if (data->cmd_count == 1)
		exit(0);
	else
	{
		printf("bash: %s: ", command);
		ft_error("numeric argument required", 2, data);
		exit(0);
	}
	return ;
}
