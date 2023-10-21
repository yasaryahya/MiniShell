/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:32 by yyasar            #+#    #+#             */
/*   Updated: 2022/11/19 19:14:51 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
	}
	else
	{
		if (slen - start < len)
			len = slen - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, (s + start), len + 1);
	}
	return (str);
}
/*
int main()
{
	char a[] = "malatyabattalgazi";
	printf("%s", ft_substr(a, 3, 10));
}
	//a dizisini 3. indeksten basla 10 char yazdır
*/