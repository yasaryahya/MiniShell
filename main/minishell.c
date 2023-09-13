/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/13 09:55:22 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	init(t_data *data, char *command)
{
    int		count;
    int		i;
    char	**str;

    count = 0;
    i = -1;
    data->b_arg = command;
    lexer(data);
    data->b_arg = data->lexer->full_str;
    printf("\033[31m---------->%s\n\033[0m", data->lexer->full_str);
    data->arg_len = ft_strlen(command);
    str = ft_split(data->lexer->full_str, ' ');
    while (str[++i]) {
        count++;
        printf("------>%s\n", str[i]);
    }
    data->arg_count = count;
    data->arg = str;
    count = 0;
    i = -1;
    while (data->envrt[++i]) {
        count++;
    }
    data->env_count = count;
    set_env(data);
}

void	minishell(t_data *data)
{
    char	*command;

    while (1) {
        signal(SIGQUIT, ft_sig);
        signal(SIGINT, ft_sig);
        command = readline("\033[31msalihshell$\033[0m ");
        if (command == NULL) {
            ft_sig(4);
        }
        add_history(command);
        init(data, command);
        parse(data);
        free(data->lexer->full_str); // Bellek sızıntısı önlemek için full_str'i serbest bırak
    }
}

void lexer(t_data *data)
{
    int		i;
	int		len;
    char	*str;

    i = 0;
    str = strdup("");
    while (data->b_arg[i]) 
	{
        if (data->b_arg[i] == '|')
            str = ft_strjoin(str, " | ");
        else if (data->b_arg[i] == '>')
            str = ft_strjoin(str, " > ");
        else if (data->b_arg[i] == '<')
            str = ft_strjoin(str, " < ");
        else if (data->b_arg[i] == ';')
            str = ft_strjoin(str, " ; ");
        else if (data->b_arg[i] == ' ')
            str = ft_strjoin(str, " ");
        else if (data->b_arg[i] == '"' || data->b_arg[i] == '\'') {
            data->lexer->index = i;
            lexer_utils(data);
            i = data->lexer->index;
			str = ft_strjoin(str,data->lexer->full_str);
        }
        else {
            len = ft_strlen(str);
            str = ft_strjoin_char(str, data->b_arg[i]);
        }
        i++;
    }
	data->lexer->full_str =	str ;
}

void lexer_utils(t_data *data)
{
    int		flag;
    int		i;
	char	*str;

    data->lexer->tek_tirnak = 0;
    data->lexer->cift_tirnak = 0;
    flag = 1;

	str = strdup(" ");
	printf("until---->%s\nuntil---->%s\n", str,data->lexer->full_str);
    i = data->lexer->index;
    while (data->b_arg[i]) 
	{
        if (data->b_arg[i] == '"' && !data->lexer->tek_tirnak && flag) {
            data->lexer->cift_tirnak = 1;
            flag = 0;
        }
        else if (data->b_arg[i] == '\'' && !data->lexer->cift_tirnak && flag) {
            data->lexer->tek_tirnak = 1;
            flag = 0;
        }
        else if (data->b_arg[i] == '"' && data->lexer->cift_tirnak) {
            data->lexer->cift_tirnak = 0;
            flag = 1;
            break;
        }
        else if (data->b_arg[i] == '\'' && data->lexer->tek_tirnak) {
            data->lexer->tek_tirnak = 0;
            flag = 1;
            break;
        }
		printf("until2---->%s\nuntil---->%s---->%d\n", str,data->lexer->full_str, i);
        str = ft_strjoin_char(str,  data->b_arg[i]);
		printf("until3---->%s\nuntil---->%s---->%d\n", str,data->lexer->full_str, i);
        i++;
    }
	printf("until4---->%s\nuntil---->%s---->%d\n", str,data->lexer->full_str,i);
    str = ft_strjoin_char(str, data->b_arg[i]);
	printf("until5---->%s\nuntil---->%s---->%d\n", str,data->lexer->full_str,i);
	str = ft_strjoin_char(str, ' ');
	printf("until6---->%s\nuntil---->%s---->%d\n", str,data->lexer->full_str,i);
	data->lexer->full_str = ft_strjoin(data->lexer->full_str,str);
	printf("until7---->%s\nuntil---->%s---->%d\n", str,data->lexer->full_str,i);
	data->lexer->index = i;
	printf("until8---->%s\nuntil---->%s,---->%d\n", str,data->lexer->full_str,i);
	}

int main(int argc, char **argv, char **envarment)
{
    t_data	data;

    (void)argc;
    (void)argv;
    data.envrt = envarment;
    data.lexer = (t_lexer *)malloc(sizeof(t_lexer));
    minishell(&data);
    return (0);
}

char *ft_strjoin_char(char *s, char c)
{
    char *new_str;
    size_t len;

    if (!s)
        return (NULL);

    len = 0;
    if (s)
        len = ft_strlen(s);

    new_str = (char *)malloc(len + 2); // Yeni karakter dizisi için bellek tahsisi

    if (!new_str)
        return (NULL);

    if (s)
        ft_strlcpy(new_str, s, len + 1);

    new_str[len] = c;
    new_str[len + 1] = '\0';

    return (new_str);
}

