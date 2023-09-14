/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/14 05:26:38 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

/**
 * @brief env komutu geldiği zaman eşittiri yazdıran ve eşittirden sonraki
 *	stringin baş ve sonundaki " işaretini kaldırıp yazan fonk.
 */
int	direct_printf(t_data *data)
{
	char *new = NULL;
	int i;

	new = (char *)malloc(sizeof(char) * ft_strlen(data->env->second));
	if (!new)
		ft_error("env_print/ malloc error", 1);
	new = data->env->second;
	i = 1;
	printf("=");
	int j = (ft_strlen(new) - 1);
	while (++i < j)
		printf("%c", new[i]);
	new[ft_strlen(new) - 1] = '\0';
	printf("\n");
	free(new);
	return (-42);
}

/**
 * @brief env komutu geldiği zaman second(eşittirden sonrası)
 * varsa "çift tırnakları" kaldırır
 */
void	control_and_printf(t_data *data)
{
	int i;
	while(data->env)
	{	
		i = 0;
		if(data->env->second[0] != '=')	
			i = -42;
		if (i != -42)
			printf("%s", data->env->first);
		if (data->env->second[1] == '"')
			i = direct_printf(data);
		if (i != -42)
			printf("%s\n", data->env->second);
		data->env = data->env->next;
	}
}

/**
 * @brief Envrt değişkenleri env veya export komutuna göre ekrana yazan fonk.
 */
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
