#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
 
typedef struct s_data 
{
	char 	**arg;
	char	*b_arg;
	int		len;
	int		echo_val;

}	t_data;

t_data a_data;


void		ft_sig(int sig);

#endif

