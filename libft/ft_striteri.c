/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:07:02 by yyasar            #+#    #+#             */
/*   Updated: 2022/11/20 11:38:59 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	ft_upper(unsigned int i, char *s)
{
	int	c;

	c = 0;
	i = 0;
	if (*s)
	{
		s[c] = s[c] - 32;
	}
}

int	main ()
{
	char p[] = "YAhya";
	ft_striteri(p, ft_upper);
	printf("%s",p);
}
*/