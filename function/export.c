/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 04:29:48 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/13 09:48:59 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
// dikkat et ft_strdup var!!!


void	check_arg(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (data->arg_count > i)
	{
		j = 0;
    	while (data->arg[j] != NULL)
		{
      		if (ft_strncmp(data->arg[i], data->arg[j], ft_strlen(data->arg[j])) == 0)
			{
        		data->arg[i] = NULL;
				if (data->arg[i + 1])
					data->arg[i] = data->arg[i + 1];
				data->arg_count--;
				break ;
      		}
			j++;
    	}
		i++;
  	}
}

void	check_arg_envrt(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (data->arg[i] != NULL)
	{
		j = 0;
    	while (data->envrt[j] != NULL)
		{
      		if (ft_strncmp(data->envrt[j], data->arg[i], ft_strlen(data->arg[i])) == 0)
			{
        		data->arg[i] = NULL;
				if (data->arg[i + 1])
					data->arg[i] = data->arg[i + 1];
				data->arg_count--;
				break ;
      		}
			j++;
    	}
		i++;
  	}
	check_arg(data);
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
	check_arg_envrt(data);
	if (data->arg_count == 1)
		env_print(data, 1);
	else
	{
		new_envrt = malloc(sizeof(char *) * (data->env_count + data->arg_count + 1));
		if (!new_envrt)
			ft_error("export/ bellek hatası1", 1);
		add_export(data, new_envrt, i, j);
		//free(new_envrt);
	}
}
