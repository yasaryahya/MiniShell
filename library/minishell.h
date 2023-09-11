/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:45 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/11 06:39:24 by yyasar           ###   ########.fr       */
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
	char			*first;
	char			*second;
	struct s_env	*next;
}		t_env;


typedef struct s_data 
{
	char	**arg; // gelen arg " " ile ayrılmış hali
	char	*b_arg; // gelen tüm arg bir alır.
	int		arg_len; // gelen tüm arg'ın uzunluğu.
	int		exit_signal;
	int		arg_count; // gelen arg sayısı
	char 	*pathname;
	char	*cmd_path;
	int		env_count; // env satır sayısı. 
	char	**envrt; // tüm env'nin olduğu yer.
	t_env	*env; // env'lerin list olarak tutulduğu struct.
	
}	t_data;

t_data		*data;

//   main 
void		minishell(t_data *data);

void		ft_sig(int sig);
void		parse(t_data *data);

void		ft_error(char *str, int flag);
void		ft_environment();
void	 	ilkarguman(t_data *data);
void		tirnak_kontrol(t_data *data);
t_env		*ft_newenv(void *content);
t_env		*ft_envlast(t_env *lst);
void		ft_envadd_back(t_env **lst, t_env *new);

int 		set_env(t_data *data);
void    	env_print(t_data *data, int flag);
void    	appendEnvNode(char *str, t_env **envList);
t_env	   *createEnvNode(char *str);
t_env	   *esitsayisi(t_env *newNode, int count, int len, char *str);

int			env_struct(t_data *base, char *new_arg);
char		**env_split(char *src);
char		*find_chr_ret_str(char *str, char c, int status);
//function
void		ft_echo(t_data *data);
void		ft_pwd(void);
void		bin_ls(void);

void		ft_exit(t_data *data);
void		cd(t_data *data);

void		export(t_data *data);
void    	export2(t_data *data, char **new_envrt, int i, int j);
void		command(t_data *data);
void   		clearEnvList(t_data *data);
void		ft_free_str(char **str);
#endif
