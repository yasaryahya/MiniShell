/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:13:22 by yyasar            #+#    #+#             */
/*   Updated: 2022/10/20 16:26:23 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *set, size_t n)
{
	size_t	len;

	len = ft_strlen(set);
	if (!*set)
		return ((char *)s1);
	while (*s1 && n-- >= len)
	{
		if (*s1 == *set && !ft_memcmp(s1, set, len))
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	a[] = "yahya42cursus";
	char	b[] =  "42";
	
	printf("%s\n", ft_strnstr(a, b, 10));
}
*/