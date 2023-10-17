/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/22 06:39:32 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Envrt değişkenleri env veya export komutuna göre ekrana yazan fonk.
 * flag = 1 ise export, flag = 0 ise env.
 */
void	env_print(t_data *data, int flag)
{
	t_env	*tmp;

	if (data->cmd_count > 1)
	{
		printf("env: %s: No such file or directory\n", data->arg[1]);
		return ;
	}
	if (flag == 0)
	{
		tmp = data->env;
		while (tmp)
		{
			if (tmp->second[0])
				printf("%s=%s\n", tmp->first, tmp->second);
			tmp = tmp->next;
		}
	}
	if (flag == 1)
	{
		tmp = data->env;
		while (tmp)
		{
			if (!tmp->second[0])
				printf("declare -x %s\n", tmp->first);
			else
				printf("declare -x %s=\"%s\"\n", tmp->first, tmp->second);
			tmp = tmp->next;
		}
	}
}
