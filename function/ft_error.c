/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:38:35 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/20 01:31:46 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	ft_error(char *str, int flag)
{
	if (flag == 1)
	{
		printf("%s", str);
		exit(EXIT_FAILURE);
	}
	else
		printf("%s", str);
	return;
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env != NULL)
	{
		tmp = env->next;
		//free(env->data);
		free(env->first);
		free(env->second);
		free(env);
		env = tmp;
	}
	env = NULL;
}