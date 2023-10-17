/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:28:28 by yyasar            #+#    #+#             */
/*   Updated: 2023/08/31 13:16:48 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%d\n", ft_isalnum(44));
	printf("%d\n", ft_isalnum(88));
	printf("%d\n", ft_isalnum(111));
	printf("%d\n", ft_isalnum(144));
}
*/
