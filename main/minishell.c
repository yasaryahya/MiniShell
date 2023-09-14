/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/14 23:27:03 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void init(t_data *data, char *command)
{
	int count = 0;
	int i = -1;
	char **str = NULL;

	count = 0;
	i = -1;
	data->b_arg = command;
	lexer(data);
	str = ft_split(data->lexer->full_str, ' ');
	while (str[++i])
		count++;
	data->arg_count = count;
	data->arg = str;
	count = 0;
	i = -1;
	while (data->envrt[++i])
		count++;
	data->env_count = count;
	set_env(data);
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
		//if(history_control(command));
		add_history(command);
		init(data, command);
		//if(!pipe_control(data))
			parse(data);
		free(data->lexer->full_str);
	}
}

void lexer(t_data *data)
{
	int i = 0;
	data->lexer->full_str = ft_strdup("");

	while (data->b_arg[i])
	{
		if (data->b_arg[i] == '|')
		{
			data->pipe_count += 1;
			data->lexer->full_str = ft_strjoin(data->lexer->full_str, " | ");
		}
		else if (data->b_arg[i] == '>')
			data->lexer->full_str = ft_strjoin(data->lexer->full_str, " > ");
		else if (data->b_arg[i] == '<')
			data->lexer->full_str = ft_strjoin(data->lexer->full_str, " < ");
		else if (data->b_arg[i] == ';')
			data->lexer->full_str = ft_strjoin(data->lexer->full_str, " ; ");
		else if (data->b_arg[i] == ' ')
			data->lexer->full_str = ft_strjoin(data->lexer->full_str, " ");
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

int main(int argc, char **argv, char **envarment)
{
	t_data data;

	(void)argc;
	(void)argv;
	data.envrt = envarment;
	data.lexer = (t_lexer *)malloc(sizeof(t_lexer));
	minishell(&data);
	free(data.lexer);
	return (0);
}
