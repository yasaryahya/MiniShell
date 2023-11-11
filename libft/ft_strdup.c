/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:47:12 by yyasar            #+#    #+#             */
/*   Updated: 2022/10/20 15:40:25 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	i;

	a = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (a == 0)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
/*
int main()
{
	char a[] = "yahya";
	printf("%s", ft_strdup(a));
}
*/