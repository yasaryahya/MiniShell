/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 22:34:26 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/07 04:49:33 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
/*
t_env	*ft_envlast(t_env *lstt)
{
	if (!lstt)
		return (0);
	while (lstt->next != NULL)
		lst = lstt->next;
	return (lstt);
}

void	ft_envadd_back(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = ft_envlast(*lst);
		temp->next = new;
	}
}

t_env	*ft_newenv(void *content)
{
	t_env	*my;

	my = (t_env *)malloc(sizeof(t_env));
	if (!my)
		return (NULL);
	my->content = ft_strdup(content);
	my->next = NULL;
	return (my);
}

void	ft_environment(void)
{
	int	i;

	i = 0;
	data->env = NULL;
	while (data->envrt[i] != NULL)
	{
		ft_envadd_back(&data->env, ft_newenv(data->envrt[i]));
		i++;
	}
}
*/