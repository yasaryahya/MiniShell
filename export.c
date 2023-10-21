/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:39:21 by yyasar            #+#    #+#             */
/*   Updated: 2023/10/21 11:15:53 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg(t_data *data, char **cmd)
{
	int 	i;
	char	c;
	char	*clear_str;
	
	i = 1;
	while (data->cmd_count > i)
	{
		clear_str = find_and_clear(cmd[i], '"', '\'', data);
		c = clear_str[0];
		if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == '=')))
		{
        	printf("bash: export: \'%s\': not a valid identifier \n", clear_str);
			free(clear_str);
			ft_error("", 2, data);
			return(0);
      	}
		free(clear_str);
		i++;
  	}
	return(1);
}

int	check_arg_envrt(t_data *data, char **cmd, int i, int j)
{
	if (check_arg(data, cmd) == 0)
		return (0);
	while (cmd[i] != NULL)
	{
		j = i+1;
    	while (cmd[j] != NULL)
		{
      		if (ft_strcmp(cmd[j], cmd[i]) == 0)
			{
        		cmd[i] = NULL;
				if (cmd[j])
					cmd[i] = cmd[j];
				data->cmd_count--;
				break ;
      		}
			j++;
    	}
		i++;
  	}
	return (1);
}

void    add_export(t_data *data, int j, char **cmd)
{
    char *clear_str;

	while (j < data->cmd_count)
	{
		clear_str = find_and_clear(cmd[j], '"', '\'', data);
        delete_env(data, clear_str, -1);
		add_env_node(clear_str, data);
        free(clear_str);
		j++;
	}
}

void export(t_data *data, char **cmd)
{	
	data->error_no = 0;
	if (check_arg_envrt(data, cmd, 0, 0) == 0)
		return ;
	if (data->cmd_count == 1)
	{
		env_print(data, 1);
	}
	else
		add_export(data, 1, cmd);
}
