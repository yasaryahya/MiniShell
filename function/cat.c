/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 01:20:04 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/06 02:30:32 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

void	cat(t_data data)
{
	char *file;
	int fd;
	char *line;

	fd = 0;	
	if(data.arg[1])
	{
		char cwd[1024];
    	if (getcwd(cwd, sizeof(cwd)) != NULL){
			
			file = ft_strjoin(cwd, "/");
			file = ft_strjoin(file, data.arg[1]);
			fd = open(file, O_RDONLY);
			line = get_next_line(fd);
			while (line)
			{
				printf("%s", line);
				line = get_next_line(fd);
			}	
		}
		else
			printf("error command cat\n");
	}
	else
		while(1)
		{
			char *str;
			str = get_next_line(0);
			printf("%s\n", str);
			if(str == NULL)
				break;
		}
}