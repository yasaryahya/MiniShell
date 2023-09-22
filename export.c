/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/22 06:44:25 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
char *nail_control_and_trim(char *str, t_data *data)
{
    char *new;

    if (str[0] == '"' || str[0] == '\'')
    {
        new = ft_strtrim(str, "\"'");
        if (!new)
            ft_error("export/ malloc error", 1, data);
    }
    else
    {
        new = ft_strdup(str);
        if (!new)
            ft_error("export/ malloc error", 1, data);
    }
    free(str);
    return (new);
}
*/
void    add_export(t_data *data, int j, char **cmd)
{
    char *clear_str;

	while (j < data->cmd_count)
	{
		//cmd[j] = nail_control_and_trim(cmd[j], data);
		clear_str = find_and_clear(cmd[j], '"', '\'');
        delete_env(data, clear_str, -1);
		add_env_node(clear_str, data);
        free(clear_str);
		j++;
	}
}

void export(t_data *data, char **cmd)
{	
	if (check_arg_envrt(data, cmd, 0, 0) == 0)
		return ;
	printf("cmd_count:%d\n", data->cmd_count);
	if (data->cmd_count == 1)
		env_print(data, 1);
	else
		add_export(data, 1, cmd);
}