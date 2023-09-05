/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/05 16:58:10 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

int exit_signal = 0;

void	minishell(char **environment)
{
	char	*command;
	t_data	data;
	data.envrt = environment;
	
	while (1)
	{
		char **str;
		signal(SIGQUIT, ft_sig);
		signal(SIGINT, ft_sig);
		command = readline("\033[31msalihshell$\033[0m ");
		add_history(command);
		data.b_arg = command;
		data.arg_len = ft_strlen(command);
		str = ft_split(command, ' ');
		data.arg = str;
		parse(data);
		ft_malloc_error(str);
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	int a = getpid();
	printf("%d", a);
	minishell(env);
	return (0);
}
