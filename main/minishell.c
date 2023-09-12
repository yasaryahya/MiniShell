/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:12 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/13 02:58:25 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"
/*
int karakterinPozisyonunuBul(const char *str, char karakter) {
    char *sonuc = strchr(str, karakter);
    if (sonuc != NULL) {
        return (int)(sonuc - str);
    }
    return -1; // Karakter bulunamazsa -1 döner
}
*/
void	init(t_data *data, char *command)
{
	int		count;
	int		i;
	char	**str;

	count = 0;
	i = -1;
	data->b_arg = command;
	//data->b_arg = pipe_fonksiyon(data);
	data->arg_len = ft_strlen(command);
	str = ft_split(command, ' ');
	//if(karakterinPozisyonunuBul(data->b_arg, 124) != -1)
	while (str[++i])
		count++;
	data->arg_count = count;
	data->arg = str;
	count = 0;
	i = -1;
	while (data->envrt[++i])
		count++;
	data->env_count = count;
	set_env(data);
}

void	minishell(t_data *data)
{
	char	*command;

	while (1)
	{
		signal(SIGQUIT, ft_sig);
		signal(SIGINT, ft_sig);
		command = readline("\033[31msalihshell$\033[0m ");
		if (command == NULL)
			ft_sig(4);
		add_history(command);
		init(data, command);
		parse(data);
	}
}
//free_list();
//ft_malloc_error(str);

int	main(int argc, char **argv, char **envarment)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.envrt = envarment;
	minishell(&data);
	return (0);
}
//clearEnvList(&data);
/*
void	pipe_fonksiyon(t_data *data)
{
	int i;
	int j;
	char *str;
	char *fullstr;

	i = 0;
	j = 0;
	flag = 0;
	while(data->b_arg[i])
	{
		if(data->b_arg[i] == '|')
			fullstr = ft_strjoin(fullstr, " | ");
		else if(data->b_arg[i] == '>')
			fullstr = ft_strjoin(fullstr, " | ");
		else if(data->b_arg[i] == '<')
			fullstr = ft_strjoin(fullstr, " | ");
		else if(data->b_arg[i] == ';')
			fullstr = ft_strjoin(fullstr, " | ");
		else if(data->b_arg[i] == '"' | data->b_arg[i] == '\'')
		{
			i++;
			while(data->b_arg[i])
			{
				if(data->b_arg[i] == '"' | data->b_arg[i] == '\'')
					break;
				else 
					str =
			}
		}
		
	}
	return (str);
}
*/