/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:08:27 by yyasar            #+#    #+#             */
/*   Updated: 2022/10/20 12:50:37 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(s);
	while (i >= j)
	{
		if (s[j] == (char)c)
		{
			return ((char *)s + j);
		}
		j++;
	}
	return (NULL);
}
/*
int main()
{
	char a[] = "yahyaysr";
   	printf("%s", ft_strchr(a, 'h'));
}
	//stringin içinde aradığı charı bulduktan sonra hepsini yazdırır
*/