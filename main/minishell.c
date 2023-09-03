/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/02 20:54:50 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	minishell(void)
{
	char	*command;
	t_data	data;

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
		ft_malloc_error(str);
		parse(data);
	}
}

int	main(void)
{
	minishell();
	return (0);
}
