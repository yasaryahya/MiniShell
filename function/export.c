/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 04:29:48 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/12 07:29:38 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
// dikkat et ft_strdup var!!!

int     add_export_check(t_data *data)
{

}

void    add_export(t_data *data, char **new_envrt, int i, int j)
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
		if (!new_envrt[i+j])
			ft_error("export/ bellek hatası3", 1);
		append_env_node(data->arg[j+1], &new_env);
		j++;
	}
	data->env = new_env;
	data->env_count += data->arg_count;
	new_envrt[i + j] = NULL;
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
        if (add_export_check(data) == 0)
            return;
		new_envrt = malloc(sizeof(char *) * (data->env_count + data->arg_count + 1));
		if (!new_envrt)
			ft_error("export/ bellek hatası1", 1);
		add_ex  port(data, new_envrt, i, j);
		free(new_envrt);
	}
	return;
}
