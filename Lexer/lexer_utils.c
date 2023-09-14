/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:22:08 by sustmas           #+#    #+#             */
/*   Updated: 2023/09/14 02:26:51 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void lexer_utils(t_data *data) {
    int flag;
    int i;
    char *str;

    data->lexer->tek_tirnak = 0;
    data->lexer->cift_tirnak = 0;
    flag = 1;

    str = ft_strdup(" ");
    str = ft_strjoin(data->lexer->full_str, str);
    i = data->lexer->index;

    while (data->b_arg[i]) {
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
        str = ft_strjoin_char(str, data->b_arg[i]);
        i++;
    }
    str = ft_strjoin_char(str, data->b_arg[i]);
    str = ft_strjoin_char(str, ' ');
    data->lexer->full_str = ft_strjoin(str, "");
    data->lexer->index = i;
    free(str); // Belleği serbest bırak
}

char *ft_strjoin_char(char *s, char c) {
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

    free(s); // s parametresi için ayrılan belleği serbest bırak

    return (new_str);
}