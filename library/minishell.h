/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:45 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/06 02:06:14 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>

typedef struct s_env
{
	char	**data;
	struct s_env	*next;
}	t_env;


typedef struct s_data 
{
	char	**arg;
	char	*b_arg;
	char	*str;
	int		arg_len;
	int		echo_val;
	int		exit_signal;
	char	**envrt;
	int		arg_count;
	t_env	env;
	
}	t_data;


void		ft_sig(int sig);
void		parse(t_data data);
void		ft_error(char *str, int flag);
void		tirnak_kontrol(t_data data);
void	 	ilkarguman(t_data data);


//function
void		ft_echo(t_data data);
void		ft_pwd(void);
void		bin_ls(void);
void		ls_genel(t_data data);
void		ls_la(void);
void 		ls();
void		ls_l();
void		ls_a();
void		ft_exit(t_data data);
void		cd(t_data data);
void		cat(t_data data);
#endif
