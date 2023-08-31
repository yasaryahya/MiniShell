/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:18:35 by yyasar            #+#    #+#             */
/*   Updated: 2023/08/31 14:44:54 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_place(char **str, char const *s1, char ch, int wordsyc)
{
	int		index;
	int		wordlen;
	int		word;

	word = 0;
	index = 0;
	wordlen = 0;
	while (word < wordsyc)
	{
		while (s1[index] != '\0' && s1[index] == ch)
			index++;
		while (s1[index] != '\0' && s1[index] != ch)
		{
			wordlen++;
			index++;
		}
		str[word] = ft_substr(s1, index - wordlen, wordlen);
		wordlen = 0;
		word++;
	}
	str[word] = 0;
	return (str);
}

static int	strcount(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		wrdsyc;

	if (!s)
		return (0);
	wrdsyc = strcount(s, c);
	str = (char **)malloc(sizeof(char *) * wrdsyc + 1);
	if (!str)
		return (0);
	ft_place(str, s, c, wrdsyc);
	return (str);
}
/*
int main(void)
{
	char	a[] = ",,yahya,yasar,malatya";
	int i = 0;
	while (ft_split(a, ',')[i])
	{
		printf("%s\n", ft_split(a, ',')[i]);
		i++;
	}
	return (0);
}*/