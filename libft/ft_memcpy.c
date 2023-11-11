/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:32:19 by yyasar            #+#    #+#             */
/*   Updated: 2022/11/19 15:28:08 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)src;
	str2 = (char *)dst;
	if (!str1 && !str2)
		return (NULL);
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	return (str2);
}
/*
int main()
{
	char a[] = "yahya";
	char b[] = "aelihas";
	printf("%s", ft_memcpy(a, b, 7));
}
*/