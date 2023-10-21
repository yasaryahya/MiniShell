/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/10/21 11:17:26 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Envrt değişkenleri env veya export komutuna göre ekrana yazan fonk.
 * flag = 1 ise export, flag = 0 ise env.
 */
void	env_print(t_data *data, int flag)
{
	t_env	*tmp;

	data->error_no = 0;
	if (data->cmd_count > 1)
	{
		printf("env: %s: No such file or directory\n", data->arg[1]);
		ft_error("", 127, data);
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
