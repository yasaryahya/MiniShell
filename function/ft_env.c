/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 02:41:59 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/06 06:46:30 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	ft_env(t_data data)
{
    if (data.arg_count == 1)
	{	// Argüman yoksa, tüm ortam değişkenlerini görüntüle
		int i;
		i = 0;
        while (data.envrt[i])
			printf("%s\n", data.envrt[i++]);    }
	else if (data.arg_count == 2)
	{
        // Bir argüman varsa, belirtilen ortam değişkenini görüntüle
        char *var_name = data.arg[1];
        char *var_value = getenv(var_name);

        if (var_value)
            printf("%s=%s\n", var_name, var_value);
        else
		{
            printf("Hata: Ortam değişkeni bulunamadı.\n");
            return;
        }
    }
	else
	{
		printf("Kullanım: env [ORTAM_DEĞİŞKENİ]\n");
		return;
	}
    return;
}
