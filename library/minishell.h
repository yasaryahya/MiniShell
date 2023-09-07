/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:45 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/07 06:51:53 by yyasar           ###   ########.fr       */
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
# include <stdbool.h>


typedef struct s_env
{
	char			*data;
	bool			is_env_equal;
	struct s_env	*next;
	struct s_env	*prev;
}		t_env;


typedef struct s_data 
{
	char	**arg;
	char	*b_arg;
	char	*str;
	int		arg_len;
	int		exit_signal;
	char	**envrt;
	int		arg_count;
	char 	*pathname;
	char	*cmd_path;
	t_env	*env;
	
}	t_data;

t_data		*data;
t_env		*env;
void		minishell(void);

void		ft_sig(int sig);
void		parse(t_data data);
void		ft_error(char *str, int flag);
void		tirnak_kontrol(t_data data);
void	 	ilkarguman(t_data data);
void		ft_environment();
t_env		*ft_newenv(void *content);
t_env		*ft_envlast(t_env *lst);
void		ft_envadd_back(t_env **lst, t_env *new);
void		ft_env(t_data *base);
void		free_list(void);

int 		set_arg(char **envp, int flag);
int			env_struct(t_data *base, char *new_arg);
char		**env_split(char *src);
char		*find_chr_ret_str(char *str, char c, int status);

//function
void		ft_echo(t_data data);
void		ft_pwd(void);
void		bin_ls(void);
//void		ls_genel(t_data data);
//void		ls_la(void);
//void 		ls();
//void		ls_l();
//void		ls_a();
void		ft_exit(t_data data);
void		cd(t_data data);
//int			cat(t_data data);
//int 		touch(t_data data);
//int 		ft_mkdir(t_data data);
//int 		rm(const char *pathname);
void		export(t_data data);
void		command(t_data data);
void 		clearEnvList();
#endif
