/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_deneme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:13:37 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/19 22:57:22 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "library/minishell.h"
/*
void ft_pipe(t_data *data)
{
    int i;
    int fd;
	char **cmdd;

    i = -1;
    fd = 0;
    data->cmd = ft_split(data->lexer->full_str, '|');
    while (data->cmd[++i])
    {
    	ft_free_malloc(data->arg);
    	data->arg = ft_split(data->cmd[i], ' ');
		cmdd = ft_split(data->cmd[i], ' ');
        if (!i)
            fd = comment(data, cmdd, 0, 1, 1);
        else if (i == data->pipe_count)
            comment(data, cmdd, fd, 1, 0);
        else
            fd = comment(data, cmdd, fd, 1, 1);
    }
	ft_free_malloc(data->cmd);
    data->pipe_count = 0;
}

*/
//  
//  data->lexer->full_str:  ls -la | grep *.c | wc -l       pipe_count: 3 
//              data->cmd:  {"ls -la", "grep *.c", "wc -l"}
//                   cmdd:  "ls", "-la"
