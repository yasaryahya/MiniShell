/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sustmas <sustmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:01:39 by yyasar            #+#    #+#             */
/*   Updated: 2023/10/21 10:58:08 by sustmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_pwd(t_data *data)
{
    char cwd[1024];

    data->error_no = 0;
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
    else
        ft_error("function/pwd: pwd Error", 127, data);
    return ;
}