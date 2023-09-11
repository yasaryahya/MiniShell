/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 04:29:48 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/11 06:44:12 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
// dikkat et ft_strdup var!!!

void    export2(t_data *data, char **new_envrt, int i, int j)
{
    t_env *new_env = data->env;
    while (i < data->env_count)
    {
        new_envrt[i] = ft_strdup(data->envrt[i]);
        if (!new_envrt[i])
            ft_error("export/ bellek hatası2", 1);
        i++;
    }
    while (j+1 < data->arg_count)
    {
        new_envrt[i+j] = ft_strdup(data->arg[j+1]);
        appendEnvNode(data->arg[j+1], &new_env);
        if (!new_envrt[i+j])
            ft_error("export/ bellek hatası3", 1);
        j++;
    }
    data->env = new_env;
    data->env_count += data->arg_count;
    new_envrt[data->env_count + data->arg_count] = NULL;
    data->envrt = new_envrt;
}

void export(t_data *data)
{
    int j;
    int i;
    char **new_envrt = NULL;

    i = 0;
    j = 0;
    if (data->arg_count == 1)
        env_print(data, 1);
    else
    {
        new_envrt = malloc(sizeof(char *) * (data->env_count + data->arg_count + 1));
        if (!new_envrt)
            ft_error("export/ bellek hatası1", 1);
        export2(data, new_envrt, i, j);
    }
    return;
}
