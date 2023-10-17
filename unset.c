/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:40:36 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/22 06:35:41 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void delete_env(t_data *data, char *delete_env, int i)
{
    t_env *current = data->env;
    t_env *prev = NULL;

	while (delete_env[++i])
		if (delete_env[i] == '=')
			break;
    while (current != NULL)
    {
        if (ft_strncmp(current->first, delete_env, i) == 0)
        {
            if (prev == NULL)
                data->env = current->next;
            else
                prev->next = current->next;
            free(current->first);
            free(current->second);
            free(current);
            return;
		}
        prev = current;
        current = current->next;
    }
}

void	unset(t_data *data, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[++i])
		delete_env(data, cmd[i], -1);
}
