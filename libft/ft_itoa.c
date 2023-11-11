/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:22:37 by yyasar            #+#    #+#             */
/*   Updated: 2022/10/20 21:14:56 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_find_digit(int n)
{
	int	digit;

	digit = 0;
	while (n > 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static	char	*ft_neg_itoa(int n)
{
	char	*snc;
	int		i;
	int		j;
	int		poz;

	poz = (n * -1);
	i = ft_find_digit(poz);
	j = ft_find_digit(poz) + 1;
	snc = (char *)malloc(sizeof(char) * (ft_find_digit(poz) + 2));
	if (!snc)
		return (0);
	while (i != 0)
	{
		snc[i] = (poz % 10) + 48;
		poz /= 10;
		i--;
	}
	snc[j] = '\0';
	snc[0] = '-';
	return (snc);
}

char	*ft_itoa(int n)
{
	char	*snc;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		return (ft_neg_itoa(n));
	snc = (char *)malloc(sizeof(char) * (ft_find_digit(n) + 1));
	j = ft_find_digit(n);
	i = ft_find_digit(n) - 1;
	while (i >= 0)
	{
		snc[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	snc[j] = '\0';
	return (snc);
}
/*
int	main()
{
	printf("%s", ft_itoa(-548767));
}
*/