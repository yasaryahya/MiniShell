/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:45 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/02 20:31:14 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>

typedef struct s_data 
{
	char	**arg;
	char	*b_arg;
	char	*str;
	int		arg_len;
	int		echo_val;

}	t_data;

void		ft_sig(int sig);
void		parse(t_data data);
void		ft_error(t_data data,int flg);
void		tirnak_kontrol(t_data data);
void	 	ilkarguman(t_data data);

#endif

