/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/08 00:49:27 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	minishell(t_data *data)
{
	char	*command;
	int		count;
	int		i;

	while (1)
	{
		
		i = -1;
		count = 0;
		char **str;
		signal(SIGQUIT, ft_sig);
		signal(SIGINT, ft_sig);
		command = readline("\033[31msalihshell$\033[0m ");
		if(command == NULL)
			ft_sig(4);
		add_history(command);
		data->b_arg = command;
		data->arg_len = ft_strlen(command);
		str = ft_split(command, ' ');
		while(str[++i])
			count++;
		data->arg_count = count;
		printf("aaa %d", count);
		data->arg = str;
		parse(data);
		ft_malloc_error(str);
		//free_list();
	}
	
}


int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	t_data data;
	data.envrt = env;
	set_env(env);
	minishell(&data);
	clearEnvList();
	return (0);
}
