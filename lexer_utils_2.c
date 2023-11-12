/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:01:56 by yyasar            #+#    #+#             */
/*   Updated: 2023/11/12 03:09:47 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	copy_to_str(t_lexer *lexer, char *str, char *full_str)
{
	size_t	str_len;
	size_t	full_str_len;
	char	*new_full_str;

	str_len = ft_strlen(str);
	full_str_len = ft_strlen(full_str);
	new_full_str = (char *)malloc(str_len + full_str_len + 1);
	if (new_full_str)
	{
		ft_strcpy(new_full_str, full_str);
		ft_strcat(new_full_str, str);
		free(full_str);
		lexer->full_str = new_full_str;
	}
}
