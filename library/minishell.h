/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:25:45 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/20 01:31:08 by yyasar           ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
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
	//char			*data;
	char			*first;
	char			*second;
	struct s_env	*next;
}		t_env;

typedef struct s_data 
{
	char	**arg;
	char	*b_arg;
	int		arg_len;
	int		exit_signal;
	int		arg_count;
	char	*pathname;
	char	*cmd_path;
	int		env_count;
	char	**envrt;
	int		pipe_count;
	char	**cmd;
	char	**pipe_cmd;

	t_env	*env;
	t_lexer	*lexer;
}	t_data;

t_data		*data;

//   main
void		minishell(t_data *data);

void		ft_sig(int sig);
void	 	parse(t_data *data);

//	free--error
void		free_function(t_data *data, int flag);
void		ft_free_malloc(char **tab);
void		free_env_list(t_env *env);

void		ft_error(char *str, int flag);
void		free_env(t_env *env);

//void		ENVironment();
void		ilkarguman(char **cmd);
int			tirnak_kontrol(char *command);
t_env		*ft_newenv(void *content);
t_env		*ft_envlast(t_env *lst);
void		ft_envadd_back(t_env **lst, t_env *new);

int			init_env(t_data *data);
void		env_print(t_data *data, int flag);
void		append_env_node(char *str, t_env **env_list);
t_env		*create_env_node(char *str);
t_env		*esitsayisi(t_env *newNode, int count, int len, char *str);

//	  UNSET
void		unset(t_data *data);
void		unset_delete(t_data *shell_data, const char *key, char **new_envrt);

int			env_struct(t_data *base, char *new_arg);
char		**env_split(char *src);
char		*find_chr_ret_str(char *str, char c, int status);
//  FUNCTION
void		ft_echo(t_data *data);
void		ft_pwd(void);
void		bin_ls(t_data *data);

void		ft_exit(t_data *data);
void		cd(t_data *data);

//	 EXPORT
void		export(t_data *data);
void		add_export(t_data *data, char **new_envrt, int i, int j);
int			ft_check_envrt(t_data *data, char *str, int i, int j);
int			check_arg_envrt(t_data *data);
int			check_arg(t_data *data);
char		*nail_control_and_trim(char *str);


void		command(t_data *data);
char		*find_path(t_data *data);

//void   		clearEnvList(t_data *data);
void		ft_free_str(char **str);
void		init(t_data *data, char *command);

void		lexer(t_data *data);
void		lexer_utils(t_data *data);
char 		*ft_strjoin_char(char *s, char c);

//	TOKEN

void		dollar_token(t_data *data);
//int			pipe_control(t_data *data);

//	 UTİLS
void    	space_one(t_data *data);
int			ft_strcmp(char *s1, char *s2);

// 	  PİPE
void		ft_pipe(t_data *data);
int			comment(t_data *data, char **cmd, int input, int output, int x);
void		redirection_to_input(char **cmd, int fd, int i);
void		redirection_to_output(char **cmd, int i, int fd, int x);
int			operation(char **cmd, int i);
char		**re_create_cmd(char **cmd, int len, int i, int j);
char		*create_path(char *cmd, char **cmd_paths);
void		ft_free_malloc(char **tab);
void 		ft_pipe_deneme(t_data *data);
void 		execute_command_with_pipe(char **command, int *input_fd, int *output_fd);
#endif
