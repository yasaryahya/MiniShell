/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:29:33 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/15 08:42:30 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

char *insert_string(char *dest, const char *src, int pos) {
    int dest_len = strlen(dest);
    int src_len = strlen(src);

    // Geçerli pozisyonu kontrol et
    if (pos < 0 || pos > dest_len) {
        printf("Hata: Geçersiz pozisyon\n");
        return dest;
    }

    // Yeni bir string oluştur ve hafızayı ayır
    char *new_str = (char *)malloc(dest_len + src_len + 1);

    // İlk kısmı kopyala (başlangıçtan belirtilen pozisyona kadar)
    strncpy(new_str, dest, pos);

    // Kopyalanacak stringi ekle
    strcpy(new_str + pos, src);

    // Geri kalan kısmı kopyala (kopyalanan stringin sonrasından sona kadar)
    strcpy(new_str + pos + src_len, dest + pos);

    // Son karakteri null byte ile sonlandır
    new_str[dest_len + src_len] = '\0';

    // Eski stringi serbest bırak
    free(dest);

    return new_str;
}

char 	first_str_token(char *str, int i)
{
	int j;
	char *first;
	
	j = 0;
	first = ft_strdup("");
	while (str[j] && j < i)
	{
		first[j] = str[j];
		j++;
	}
	return (first);
}

char 	last_str_token(char *str, int i)
{
	int j;
	char *last;
	
	j = 0;
	i++;
	last = ft_strdup("");
	while (str[i])
	{
		last[j] = str[i];
		j++;
		i++;
	}
	return (last);
}

char	*recursive_token(char *str)
{
	char	*str_2;
	int		i;
	int		j;
	char	*retrn;

	i = 0;
	j = -1;

	str_2 = ft_strdup("");
	while(str[i] && (str[i] != '|' || str[i] != '>' || str[i] != '<'))
		i++;

	if (str[i] == '|' || str[i] == '>' ||str[i] == '<')
	{
		str_2 = first_str_token(str, i); 
		str = last_str_token(str, i);
		if(str[i] == '|')
			j = 0;
		else if(str[i] == '<')
			j = 1;
		else
			j = 2;
	}
	i++;
	while(str[i] && (str[i] != '|' || str[i] != '>' || str[i] != '<'))
		i++;
	if (j == 0)
	{	
		retrn = pipe_token(str_2);
		str_2 = insert_string(str, dosya, i--);
	}
	else if(j == 1)
	{
		retrn = input_token(str_2);
		str_2 = insert_string(str_2, retrn, i--);
	}
	else if(j == 2)
	{
		retrn = output_token(str);
		str_2 = insert_string(str_2, dosya, i--);
	}
	
	return(str);
}