/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 04:29:48 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/08 01:05:04 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
// dikkat et ft_strdup var!!!

/*
void	export2(void)
{
	int 	env_count;
	char	*new;
	int 	i;
	
	env_count = 0;
	while (data->envrt[env_count])
		env_count++;
	data->envrt = malloc(sizeof(char) * (data->arg_count + env_count));
	i = -1;
	while ((data->arg_count - 1) > ++i)
	{
		new = data->arg[i + 1];
		data->envrt[env_count + i] = ft_strdup(new);
	}
	data->envrt[env_count + data->arg_count] = "\0";
	return;
}

void	export(t_env *env)
{
	int i;
	i = 0;

	if (data->arg_count == 1)
		printf("wertasd");
	else if (data->arg_count >= 2)
	{
		export2();
		//ft_error("export/ 2 arg hatası ", 0);
	}
	return;	
}
*/