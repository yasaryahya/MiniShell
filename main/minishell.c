/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/20 00:18:14 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void init(t_data *data, char *command)
{
	int count;
	int i;

	count = 0;
	data->b_arg = command;
	lexer(data);
	space_one(data);
	printf("Full str :%s\n", data->lexer->full_str);
	tirnak_kontrol(data->lexer->full_str);
	data->arg = ft_split(data->lexer->full_str, ' ');
	i = -1;
	while (data->arg[++i])
		count++;
	data->arg_count = count;
	count = 0;
	i = -1;
	while (data->envrt[++i])
		count++;
	data->env_count = count;
	init_env(data);
}

void minishell(t_data *data)
{
	char *command;

	while (1)
	{
		signal(SIGQUIT, ft_sig);
		signal(SIGINT, ft_sig);
		command = readline("\033[31msalihshell$\033[0m ");
		if (command == NULL)
			ft_sig(4);
		add_history(command);
		init(data, command);
		if(data->pipe_count == 0)
			parse(data);
		else
			ft_pipe(data);
		free(data->lexer->full_str);
	}
}

void lexer(t_data *data)
{
	int i;

	data->lexer->full_str = ft_strdup("");
	data->pipe_count = 0;
	i = 0;
	while (data->b_arg[i])
	{
		if (data->b_arg[i] == '|')
		{
			data->pipe_count += 1;
			data->lexer->full_str = ft_strjoin(data->lexer->full_str, " | ");
		}
		else if (data->b_arg[i] == '>')
		{
			if (data->b_arg[i+1] == '>')
			{
				data->lexer->full_str = ft_strjoin(data->lexer->full_str, " >> ");
				i++;
			}
			else
				data->lexer->full_str = ft_strjoin(data->lexer->full_str, " > ");
		}
		else if (data->b_arg[i] == '<')
		{
			if (data->b_arg[i+1] == '<')
			{
				data->lexer->full_str = ft_strjoin(data->lexer->full_str, " << ");
				i++;	
			}
			else
				data->lexer->full_str = ft_strjoin(data->lexer->full_str, " < ");
		}
		else if (data->b_arg[i] == ';')
			data->lexer->full_str = ft_strjoin(data->lexer->full_str, " ; ");
		else if (data->b_arg[i] == '$')
		{	
			data->lexer->index = i+1;
			dollar_token(data);
			i = data->lexer->index;
		}
		else if (data->b_arg[i] == '"' || data->b_arg[i] == '\'')
		{
			data->lexer->index = i;
			lexer_utils(data);
			i = data->lexer->index;
		}
		else
			data->lexer->full_str = ft_strjoin_char(data->lexer->full_str, data->b_arg[i]);	
		i++;
	}
}
