/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:24:54 by yyasar            #+#    #+#             */
/*   Updated: 2022/11/20 00:16:52 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char	a[] = "salih";
	char	b[] = "yahya";
	
	printf("%zu", ft_strlcpy(a, b, 44));
}
*/
