/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:53:30 by yyasar            #+#    #+#             */
/*   Updated: 2022/10/20 16:13:20 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	join = malloc(sizeof(char)
			* (ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1));
	if (!s1 || !s2 || !join)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}
/*
int	main(void)
{
	char	a[] = "44";
	char	b[] = "malatya";
	printf("%s", ft_strjoin(a, b));
}*/
