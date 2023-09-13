/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:45 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/13 09:14:43 by yyasar           ###   ########.fr       */
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
# include <stdbool.h>

typedef	struct s_lexer
{
	char	*full_str;
	int		index;
	int		cift_tirnak;
	int		tek_tirnak;
}		t_lexer;


typedef struct s_env
{
	char			*data;
	char			*first;
	char			*second;
	struct s_env	*next;
}		t_env;

typedef struct s_data 
{
// gelen arg " " ile ayrilmis hali
	char	**arg;
// gelen tum arg bir alir.
	char	*b_arg;
// gelen tum arg'in uzunlugu.
	int		arg_len;
	int		exit_signal;
// gelen arg sayisi
	int		arg_count;
	char	*pathname;
	char	*cmd_path;
// env satir sayisi.
	int		env_count;
// tum env'nin oldugu yer.
	char	**envrt;
// env'lerin list olarak tutuldugu struct.
	t_env	*env;
	t_lexer	*lexer;
}	t_data;

t_data		*data;

//   main 
void		minishell(t_data *data);

void		ft_sig(int sig);
void		parse(t_data *data);

//		free--error
void		ft_error(char *str, int flag);
void		free_env(t_env **env);

//void		ENVironment();
void		ilkarguman(t_data *data);
void		tirnak_kontrol(t_data *data);
t_env		*ft_newenv(void *content);
t_env		*ft_envlast(t_env *lst);
void		ft_envadd_back(t_env **lst, t_env *new);

int			set_env(t_data *data);
void		env_print(t_data *data, int flag);
void		append_env_node(char *str, t_env **env_list);
t_env		*create_env_node(char *str);
t_env		*esitsayisi(t_env *newNode, int count, int len, char *str);

//	UNSET
void		unset(t_data *data);
void		unset_delete(t_data *shell_data, const char *key, char **new_envrt);

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
void		add_export(t_data *data, char **new_envrt, int i, int j);
void		command(t_data *data);
//void   		clearEnvList(t_data *data);
void		ft_free_str(char **str);
void		init(t_data *data, char *command);

void		lexer(t_data *data);
void		lexer_utils(t_data *data);
char 		*ft_strjoin_char(char *s, char c);
#endif
