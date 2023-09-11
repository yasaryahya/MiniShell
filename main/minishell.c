/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/11 05:38:20 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	init(t_data *data)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (data->envrt[++i])
		count++;
	data->env_count = count;
	printf("%d\n", data->env_count);
	set_env(data);
}

void	minishell(t_data *data)
{
	char	*command;
	int		count;
	int		i;

	while (1)
	{
		i = -1;
		count = 0;
		char **(str);
		signal(SIGQUIT, ft_sig);
		signal(SIGINT, ft_sig);
		command = readline("\033[31msalihshell$\033[0m ");
		if (command == NULL)
			ft_sig(4);
		add_history(command);
		data->b_arg = command;
		data->arg_len = ft_strlen(command);
		str = ft_split(command, ' ');
		while (str[++i])
			count++;
		data->arg_count = count;
		printf("count: %d\n", count);
		data->arg = str;
		init(data);
		parse(data);
		//ft_malloc_error(str);
		//free_list();
	}
}

int	main(int argc, char **argv, char **envarment)
{
	(void)argc;
	(void)argv;
	t_data	data;

	data.envrt = envarment;
	//set_env(&data);
	minishell(&data);
	clearEnvList(&data);
	return (0);
}
