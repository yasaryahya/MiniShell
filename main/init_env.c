/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:14:22 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/18 06:45:56 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

/*
 * @brief gelen new_env stringini eşittirden öncesi ve eşittirden sonrası
 * olarak ayırıyoruz, eşittirden öncesi t_env->first 'e atıyoruz, 
 * eşittirden sonrasıda başına ve sonuna " işareti koyarak t_env->second'a atıyoruz.
 */
t_env	*esitsayisi(t_env *new_node, int count, int len, char *str)
{
	char	*s;

	if (new_node)
	{
		if (count >= 1)
		{
			s = ft_strjoin("=\"", (ft_strchr(str, 61) + 1));
			new_node->first = ft_substr(str, 0, len);
			new_node->second = ft_strjoin(s, "\"");
			free(s);
		}
		else
		{
			new_node->first = ft_strdup(str);
			new_node->second = ft_strdup("");
		}
		new_node->data = ft_strdup(str);
		new_node->next = NULL;
	}
	return (new_node);
}

/**
 * @brief gelen envermant değişken stringini kontrol ediyoruz.
 * eşittir varmı yokmu, varsa kaç tane var.
 */
t_env	*create_env_node(char*str)
{
	int		len;
	int		count;
	t_env	*new_node;

	len = 0;
	count = 0;
	while (str[len])
	{
		if (str[len] == '=')
			count++;
		len++;
	}
	len = 0;
	while (str[len])
	{
		if (str[len] == '=')
			break ;
		len++;
	}
	new_node = (t_env *)malloc(sizeof(t_env));
	return (esitsayisi(new_node, count, len, str));
}

/**
 * @brief Envrt değişkenlerini List yapısına bağladığımız yer,
 * gelen listi son düğüme ekliyoruz ve t_env tütürndeki structa
 * verileri atıyoruz.
 */
void	append_env_node(char *str, t_env **env_list)
{
	t_env	*temp;
	t_env	*new_node;

	new_node = create_env_node(str);
	if (!new_node)
		ft_error("set_env/ bellek hatası", 1);
	if (!(*env_list))
		*env_list = new_node;
	else
	{
		temp = *env_list;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

/**
 * @brief Envrt değişkenlerini ilk durumda List yapısına bağladığımız yer
 * t_env tütürndeki struct verileri atıyoruz.
 */
int	init_env(t_data *data)
{
	int		i;
	t_env	*env_list;

	i = -1;
	env_list = NULL;
	while (data->envrt[++i] != NULL)
		append_env_node(data->envrt[i], &env_list);
	data->env = env_list;
//free_env(&env_list);	
	return (1);
}
