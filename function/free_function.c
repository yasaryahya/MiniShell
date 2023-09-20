/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 01:52:25 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/20 01:31:30 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void free_env_list(t_env *env)
{
    while (env)
    {
        t_env *temp = env;
        env = env->next;
        //free(temp->data);
        free(temp->first);
        free(temp->second);
        free(temp);
    }
    free(env);
}

void ft_free_malloc(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void	free_function(t_data *data, int flag)
{
	if (flag == 42)
	{
		ft_free_malloc(data->arg);
        free_env_list(data->env);
        free(data->b_arg);
        free(data->lexer->full_str);
	}
	return ;
}