/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:21:46 by sustmas           #+#    #+#             */
/*   Updated: 2023/11/11 22:32:01 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _CRTDBG_MAP_ALLOC

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_lexer
{
	char				*full_str;
	int					index;
	int					cift_tirnak;
	int					tek_tirnak;
}						t_lexer;

typedef struct s_env
{
	char				*first;
	char				*second;
	struct s_env		*next;
}						t_env;

typedef struct s_arguman
{
	char				*first;
	char				*second;
	struct s_arguman	*next;
}						t_arguman;

typedef struct s_data
{
	char				**arg;
	char				*b_arg;
	char				**cmd;
	int					quotes_flag;
	int					token;
	int					flag_token;
	int					i;
	int					a;
	int					has_pipe;
	int					error_no;
	int					flag_dollar;
	int					flag_input;
	int					pipe_count;
	int					cmd_count;
	char				**envrt;
	char				*cmd_path;
	t_env				*env;
	t_lexer				*lexer;
	t_arguman			*arguman;
}						t_data;

//		MAİN
void					ft_sig(int sig);
int						init_env(t_data *data);
void					ft_error(char *str, int flag, t_data *data);

//		ENV
void					add_env_node(char *str, t_data *data);
t_env					*create_env(char *str, t_data *data);
t_env					*node_add(t_env *new_node, int *count, int *len,
							char *str);
void					env_print(t_data *data, int flag);
void					control_and_printf(t_data *data);
int						direct_printf(t_env *tmp);
//		 ARGUMAN
int						init_arguman(t_data *data);
void					add_arg_node(char *str, t_data *data);
int						ft_arguman_add(char **cmd, t_data *data);
t_arguman				*create_arguman(char *str);
t_arguman				*node_add_arg(t_arguman *new_node, int *count, int *len,
							char *str);

//  	LEXER
void					lexer(t_data *data);
void					lexer_token_quote(t_data *data);
void					lexer_token_quote_2(t_data *data);
void					dollar_token(t_data *data);
void					lexer_token_output(t_data *data);
void					lexer_token_input(t_data *data);
void					lexer_token_pipe(t_data *data);

//		EXPORT
void					export(t_data *data, char **cmd);
void					add_export(t_data *data, int j, char **cmd);
int						ft_check_envrt(t_data *data, char *cmd);
char					*add_quotes(const char *str, int start);
int						check_arg_envrt(t_data *data, char **cmd, int i, int j);
int						check_arg(t_data *data, char **cmd);
int						delete_env(t_data *data, char *delete_env, int i);
int						delete_arg(t_data *data, char *delete_arg, int i);

//		PİPEX
void					pipex(t_data *data, int i, int fd);
int						comment(t_data *data, char **cmd, int input,
							int output);
int						create_child_process(char **cmd, t_data *data,
							int input, int output);
int						create_pipe(int *pipefd);
char					**ft_free_malloc(char **tab);
void					ft_free_str(char **str);
char					*add_character_to_index(char *str, char c, int i);
char					*create_path(char *cmd, char **cmd_paths);
char					**re_create_cmd(char **ex_cmd, int len, int i, int j);
int						operation(char *x);
char					*re_create_input(char *input);
void					execute_commands(t_data *data, char **cmd, int *fd);
void					execute_first_command(t_data *data, char **cmd,
							int *fd);

//		PARSE
void					parse(char **command, t_data *data);
void					parse_two(char **command, t_data *data);
void					parse_three(char **command, t_data *data,
							char *new_cmd);
void					redirection_to_input(char **cmd, int fd, int i);
void					redirection_to_output(char **cmd, int i, int fd, int x);

// 		FREE
void					free_data(t_data *data, char *command);
void					free_lexer(t_data *data);

//		FUNCTİON
void					slash(char **cmd, t_data *data);
void					ft_exit(t_data *data, char *command);
void					ft_pwd(t_data *data);
int						ft_echo(char **cmd, int i, t_data *data);
void					find_env_dollar(t_data *data, char *str);
void					ft_cd(char **command, t_data *data);
void					cd_two(char *home, char **command, t_data *data);
void					cd_three(char *home, char **command, char *str,
							t_data *data);
void					command_function(t_data *data, char **command);
char					*to_lowercase(char *str);
char					*find_and_clear(char *str, int search1, int search2,
							t_data *data);
void					unset(t_data *data, char **cmd);
char					*find_value(char *key, t_data *data);
int						quotes_control(char *command);
void					set_args(t_data *data);

#endif
