/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/11 06:16:13 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void    env_print(t_data *data, int flag)
{
    if (flag == 0)
    {   
        while (data->env)
        {
            printf("%s", data->env->first);
            printf("%s\n", data->env->second);
            data->env = data->env->next;
        }
    }
    if (flag == 1)
    {
        while (data->env)
        {
            printf("declare -x %s", data->env->first);
            printf("%s\n", data->env->second);
            data->env = data->env->next;
        }   
    }
    return;
}