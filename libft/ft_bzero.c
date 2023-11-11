/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:21:49 by yyasar            #+#    #+#             */
/*   Updated: 2022/10/20 13:13:36 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

/*
#include <strings.h>
int	main()
{
	char d[] = "4cursus";
	
	printf("%s", ft_bzero(d, 3));
	printf("\n--%s", bzero(d, 5));
}
*/
