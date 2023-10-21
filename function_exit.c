/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 21:46:41 by yyasar            #+#    #+#             */
/*   Updated: 2023/10/21 11:49:15 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
