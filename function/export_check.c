/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:32:46 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/14 02:38:13 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

/**
 * @brief Girdiğimiz arg'ı envrt ile karşılaştırıyor,
 * envrt'de varsa olduğu indexi döndürüyor yoksa -42 döndürür.
 */
int	ft_check_strdup(t_data *data, char *str, int i, int j)
{
	while (data->envrt[i])
	{
		j = 0;
		while (data->envrt[i][j])
		{
			if(data->envrt[i][j] == '=')
				break ;
			j++;
		}
		if (ft_strncmp(data->envrt[i], str, (j - 1)) == 0)
			return (i);
		i++;
	}
	return (-42);
}


/**
 * @brief Girdiğimiz arg'lar kontrol eder arguman'nın içinde
 *  sayı veya noktalama işareti var ise hatalı kullanım mesajı döndürür.
 */
int	check_arg(t_data *data)
{
	int 	i;
	int 	j;
	char	c;
	
	i = 1;
	while (data->arg_count > i)
	{
		j = 0;
    	while (data->arg[i][j] != '\0')
		{
			c = data->arg[i][j];
			if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c == 61)))
			{
        		printf("export: not an identifier: %s\n", data->arg[i]);
				return(0);
      		}
			j++;
    	}
		i++;
  	}
	return(1);
}

/**
 * @brief Girdiğimiz arg'ları kontrol eder aynı argüma girilmişse birini siler.
 */
int	check_arg_envrt(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	if (check_arg(data) == 0)
		return (0);
	while (data->arg[i] != NULL)
	{
		j = 1;
    	while (data->arg[i + j] != NULL)
		{
      		if (ft_strncmp(data->arg[j], data->arg[i], ft_strlen(data->arg[i])) == 0)
			{
        		data->arg[i] = NULL;
				if (data->arg[i + 1])
					data->arg[i] = data->arg[i + 1];
				data->arg_count--;
				break ;
      		}
			j++;
    	}
		i++;
  	}
	return (1);
}
