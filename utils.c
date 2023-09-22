/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:00:19 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/22 06:15:34 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *to_lowercase(char *str)
{
    char *new;
    int (i) = -1;

    if (str == NULL)
        return NULL;
    new = (char *)malloc(ft_strlen(str) + 1);
    if (new == NULL)
        return NULL;
    while (str[++i])
        new[i] = ft_tolower(str[i]);
    new[i] = '\0';
    return (new);
}

char *find_and_clear(char *str, int search1, int search2)
{
	int (i) = -1;
    int (j) = 0;

	char *new_str = malloc(ft_strlen(str) + 1);
	while (str[++i])
	{
		if ((str[i] != search1) && (str[i] != search2))
		{
			new_str[j++] = str[i];
		}
	}
	new_str[j] = '\0';
	return new_str;
}
