/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguman_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 04:59:59 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/23 06:10:11 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_arguman	*node_add_arg(t_arguman *new_node, int *count, int *len, char *str)
{
	if (new_node)
	{
		if (*count >= 1)
		{
			new_node->first = ft_substr(str, 0, *len);
			new_node->second = ft_strdup(ft_strchr(str, 61) + 1);
		}
		else
		{
			new_node->first = ft_strdup(str);
			new_node->second = ft_strdup("");
		}
	}
	return (new_node);
}

t_arguman *create_arguman(char *str)
{
    int len = 0;
    int count = 0;
    t_arguman *new_node;

    len = 0;
    count = 0;
    new_node = (t_arguman *)malloc(sizeof(t_arguman));
    if (!new_node)
		return NULL;
    while (str[len])
    {
        if (str[len] == '=')
        {
            count = 1;
            break;
        }
        len++;
    }
    new_node = node_add_arg(new_node, &count, &len, str);
    return (new_node);
}

void	add_arg_node(char *str, t_data *data)
{
	t_arguman	*temp;
	t_arguman	*new_node;

	new_node = create_arguman(str);
	new_node->next = NULL;
	if (!new_node)
		ft_error("env_init/ malloc error", 1, data);
	if (data->arguman == NULL)
		data->arguman = new_node;
	else
	{
		temp = data->arguman;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

int	init_arguman(t_data *data)
{
	int		i;

	i = -1;
	while (data->envrt[++i] != NULL)
		add_arg_node(data->envrt[i], data);
	return (1);
}
