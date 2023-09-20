/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:32:46 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/19 23:19:46 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

/**
 * @brief Girdiğimiz arg'ı envrt ile karşılaştırıyor,
 * envrt'de varsa olduğu indexi döndürüyor yoksa -42 döndürür.
 */
int	ft_check_envrt(t_data *data, char *str, int i, int j)
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
		if (ft_strncmp(data->envrt[i], str, j) == 0)
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
	char	c;
	
	i = 1;
	while (data->arg_count > i)
	{
			c = data->arg[i][0];
			if (!((c >= 65 && c <= 90) || (c >= 97 && c <= 122) 
				|| (c == '=') || (c == '"') || (c == '\'')))
			{
        		printf("export: not an identifier: %s\n", data->arg[i]);
				return(0);
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
	
	if (check_arg(data) == 0)
		return (0);
	i = 0;
	while (data->arg[i] != NULL)
	{
		j = i+1;
    	while (data->arg[j] != NULL)
		{
      		if (ft_strcmp(data->arg[j], data->arg[i]) == 0)
			{
        		data->arg[i] = NULL;
				if (data->arg[j])
					data->arg[i] = data->arg[j];
				data->arg_count--;
				break ;
      		}
			j++;
    	}
		i++;
  	}
	return (1);
}
