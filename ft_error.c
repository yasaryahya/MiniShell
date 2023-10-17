/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:45:12 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/22 03:01:56 by yyasar           ###   ########.fr       */
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
		exit(1);
	}
	else if (flag == 2) // dosya , dizin hatası
	{
		printf("%s", str);
		data->error_no = 1;
	}
	else if (flag == 127) //sıkıntılı çalışma, komut bulunamadı
	{
		printf("%s", str);
		data->error_no = 127;
	}
	return ;
}
