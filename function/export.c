/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 04:29:48 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/18 05:23:48 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
// dikkat et ft_strdup var!!!

char	**ft_free_envrt(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}


char	*nail_control_and_trim(char *str)
{
	char	*new;

	new = (char *)malloc(sizeof(char)* ft_strlen(str));
	if (!new)
		ft_error("export/ malloc error", 1);
	if (str[0] == '"')
		new = ft_strtrim(str, "\"");
	else if (str[0] == '\'')
		new = ft_strtrim(str, "\'");
	else
		new = str;
	return (new);
}

/**
 * @brief export ile birden fazla argüman gelirse gerekli kontrolleri
 * yapıp data->envrt ve t_env verilerine ekliyoruz.
 */
void    add_export(t_data *data, char **new_envrt, int i, int j)
{
	int 	x;
	t_env	*new_env = data->env;

	while (i < data->env_count)
	{
		new_envrt[i] = ft_strdup(data->envrt[i]);
		if (!new_envrt[i])
			ft_error("export/ bellek hatası2", 1);
		i++;
	}
	while (j+1 < data->arg_count)
	{   
		data->arg[j+1] = nail_control_and_trim(data->arg[j+1]);
		if (ft_check_envrt(data, data->arg[j+1], 0, 0) == -42)
		{
			new_envrt[i+j] = nail_control_and_trim(data->arg[j+1]);
			if (!new_envrt[i+j])
				ft_error("export/ bellek hatası3", 1);
			append_env_node(data->arg[j+1], &new_env);
		}
		else
		{
			x =	ft_check_envrt(data, data->arg[j+1], 0, 0);
			new_envrt[x] = data->arg[j+1];
		}
		j++;
	}
	data->env = new_env;
	data->env_count += data->arg_count;
	new_envrt[i + j] = NULL;
	data->envrt = new_envrt;
}

/**
 * @brief export komutu geliyor tek argüman gelirse env_print'e atıyoruz
 * birden fazla ise kontrol edip data->envrt ve t_env verilerine ekliyoruz.
 */
void export(t_data *data)
{
	char **new_envrt = NULL;

	if (check_arg_envrt(data) == 0)
		return ;
	if (data->arg_count == 1)
		env_print(data, 1);
	else
	{
		new_envrt = malloc(sizeof(char *) * (data->env_count + data->arg_count + 1));
		if (!new_envrt)
			ft_error("export/ bellek hatası1", 1);
		add_export(data, new_envrt, 0, 0);
	}
	//ft_free_envrt(new_envrt);
}
