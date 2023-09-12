/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:52:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/12 06:57:13 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void unset_delete(t_data *shell_data, const char *key, char **new_envrt)
{
    int index_to_remove = -1;

    for (int i = 0; i < shell_data->env_count; i++)
    {
        if (ft_strncmp(shell_data->envrt[i], key, ft_strlen(key)) == 0)
        {
            index_to_remove = i;
            break;
        }
		else
			new_envrt[i] = shell_data->envrt[i];
    }

    if (index_to_remove != -1)
    {
        free(shell_data->envrt[index_to_remove]);

        for (int i = index_to_remove; i < shell_data->env_count - 1; i++)
        {
            new_envrt[i] = shell_data->envrt[i + 1];
        }
        new_envrt[shell_data->env_count - 1] = NULL;
		shell_data->envrt = new_envrt;
        shell_data->env_count--;
    }
}

void	unset(t_data *data)
{
	if (data->arg_count == 1)
		return ;
	else if (data->arg_count > 1)
	{
		int i;
		i = 1;
    	while (i < data->arg_count)
		{
			char **new_envrt = data->envrt;
			new_envrt =(char **)malloc(sizeof(char *) * data->env_count + 2);
			if (!new_envrt)
				ft_error("unset/ malloc error", 1);
    		unset_delete(data, data->arg[i], new_envrt);
			free(new_envrt);
			i++;
		}
	}
    return ;
}