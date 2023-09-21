/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/21 03:47:55 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief env komutu geldiği zaman eşittiri yazdıran ve eşittirden sonraki
 *	stringin baş ve sonundaki " işaretini kaldırıp yazan fonk.
 */
int	direct_printf(t_env *tmp)
{
	char	*new;
	int		i;
	int		j;

	new = tmp->second;
	i = 1;
	printf("=");
	j = (ft_strlen(new) - 1);
	while (++i < j)
		printf("%c", new[i]);
	printf("\n");
	return (-42);
}

/**
 * @brief env komutu geldiği zaman second(eşittirden sonrası)
 * varsa "çift tırnakları" kaldırır
 */
void	control_and_printf(t_data *data)
{
	t_env	*tmp;
	int		i;

	tmp = data->env;
	while (tmp)
	{
		i = 0;
		if (tmp->second[0] != '=')
			i = -42;
		if (i != -42)
			printf("%s", tmp->first);
		if (tmp->second[1] == '"')
			i = direct_printf(tmp);
		if (i != -42)
			printf("%s\n", tmp->second);
		tmp = tmp->next;
	}
}

/**
 * @brief Envrt değişkenleri env veya export komutuna göre ekrana yazan fonk.
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
		control_and_printf(data);
	if (flag == 1)
	{
		tmp = data->env;
		while (tmp)
		{
			printf("declare -x %s", tmp->first);
			printf("%s\n", tmp->second);
			tmp = tmp->next;
		}
	}
}
