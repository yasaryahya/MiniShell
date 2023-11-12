/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 07:07:46 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/11 21:57:31 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

void	delete_arguman(t_data *data, char *delete, int i)
{
	t_arguman	*current;
	t_arguman	*prev;

	current = data->arguman;
	prev = NULL;
	while (delete[++i])
		if (delete[i] == '=')
			break ;
	while (current != NULL)
	{
		if (ft_strncmp(current->first, delete, i) == 0)
		{
			if (prev == NULL)
				data->arguman = current->next;
			else
				prev->next = current->next;
			free(current->first);
			free(current->second);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
	data->error_no = 0;
}

int	check_arguman(char **cmd, t_data *data)
{
	int		i;
	char	c;

	i = 1;
	while (data->cmd_count > i)
	{
		c = cmd[i][0];
		if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == '=')))
		{
			printf("bash: export: \'%s\': not an identifier: \n", cmd[i]);
			ft_error("", 127, data);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_arguman_add(char **cmd, t_data *data)
{
	char	*clear_str;

	int (i) = 0;
	data->error_no = 0;
	if (check_arguman(cmd, data) == 0)
		return (0);
	while (i < data->cmd_count)
	{
		clear_str = find_and_clear(cmd[i], '"', '\'', data);
		if (delete_env(data, clear_str, 1) == 1)
			add_env_node(clear_str, data);
		else
		{
			delete_arguman(data, clear_str, -1);
			add_arg_node(clear_str, data);
		}
		free(clear_str);
		i++;
	}
	return (1);
}
