/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:45:12 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/22 00:37:40 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_args(t_data *data)
{
	if(data)
	{
		data->arg = NULL;
		data->b_arg = NULL;
		data->cmd_path = NULL;
	}
}

void	init_count(t_data *data)
{
	t_env	*current;
	int		count;
	int		i;

	count = 0;
	i = -1;
	current = data->env;
	while (current)
	{
		count++;
		current = current->next;
	}
	data->env_count = count;
}

void	init(t_data *data, char *command)
{
	data->b_arg = ft_strdup(command);
	data->pipe_count = 0;
	lexer(data);
	printf("Full str :%s\n", data->lexer->full_str);
}

void	minishell(t_data *data)
{
	char	*command;

	init_env(data);
	while (1)
	{
		signal(SIGQUIT, ft_sig);
		signal(SIGINT, ft_sig);
		command = readline("\033[31msalihshell$\033[0m ");
		if (command == NULL)
			ft_sig(4);
		add_history(command);
		data->lexer = (t_lexer *)malloc(sizeof(t_lexer));
		init(data, command);
		if (data->pipe_count > 0)
			pipex(data, -1, 0);
		else
		{
			data->arg = ft_split(data->lexer->full_str, ' ');
			parse(data->arg, data);
		}
		free_data(data, command);
		//free(lexer);
	}
}

int	main(int argc, char **argv, char **envarment)
{
	t_data	data;

	(void)argc;
	(void)argv;
	set_args(&data);
	data.env = NULL;
	data.lexer = NULL;
	data.envrt = envarment;
	minishell(&data);
	return (1);
}