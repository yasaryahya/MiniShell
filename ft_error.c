/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:45:12 by sustmas           #+#    #+#             */
/*   Updated: 2023/11/11 22:32:23 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_error(char *str, int flag, t_data *data)
{
	if (flag == 1)
	{
		printf("%s", str);
		data->error_no = 1;
		exit(1);
	}
	else if (flag == 2)
	{
		printf("%s", str);
		data->error_no = 1;
	}
	else if (flag == 127)
	{
		printf("%s", str);
		data->error_no = 127;
	}
	return ;
}
