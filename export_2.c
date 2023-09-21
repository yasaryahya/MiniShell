/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/21 09:41:33 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void delete_env(t_data *data, const char *delete_env, int i)
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

int	check_arg(t_data *data, char **cmd)
{
	int 	i;
	char	c;
	
	i = 1;
	while (data->cmd_count > i)
	{
			c = cmd[i][0];
			if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122) 
				|| (c == '=') || (c == '"') || (c == '\'')))
			{
        		printf("export: not an identifier: %s\n", cmd[i]);
				return(0);
      		}
		i++;
  	}
	return(1);
}

int	check_arg_envrt(t_data *data, char **cmd, int i, int j)
{
	if (check_arg(data, cmd) == 0)
		return (0);
	while (cmd[i] != NULL)
	{
		j = i+1;
    	while (cmd[j] != NULL)
		{
      		if (ft_strcmp(cmd[j], cmd[i]) == 0)
			{
        		cmd[i] = NULL;
				if (cmd[j])
					cmd[i] = cmd[j];
				data->cmd_count--;
				break ;
      		}
			j++;
    	}
		i++;
  	}
	return (1);
}
