/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 00:47:38 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/18 06:46:38 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

int	main(int argc, char **argv, char **envarment)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.envrt = envarment;
	data.lexer = (t_lexer *)malloc(sizeof(t_lexer));
	minishell(&data);
	free(data.lexer);
	return (0);
}
