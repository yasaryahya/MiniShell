/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/11 19:44:43 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	control_and_printf(t_data *data)
{
	char *new;
	int i;
	while(data->env)
	{
		printf("%s", data->env->first);
		if(data->env->second[1] == '"')
		{
			new = (char *)malloc(sizeof(char) * ft_strlen(data->env->second));
			new = data->env->second;
			i = 1;
			printf("=");
			int j = (ft_strlen(new) - 1);
			while (++i < j)
				printf("%c", new[i]);
			new[ft_strlen(new) - 1] = '\0';
			printf("\n");
			free(new);
		}
		else
			printf("%s\n", data->env->second);
		data->env = data->env->next;
	}
}

void	env_print(t_data *data, int flag)
{
	if (data->arg_count > 1)
	{
	    printf("env: %s: No such file or directory\n", data->arg[1]);
	    return;
	}
	if (flag == 0)
		control_and_printf(data);
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
