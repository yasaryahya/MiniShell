/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:53:32 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/23 05:47:52 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

/**
 * @brief Gönderdiğimiz PATH stringini data->envr içinde arıyor,
 * bulduğu indexte path=xxxx path'den sonrasını döndürüyor. Yoksa null.
 */

char *find_value(char *key, t_data *data)
{
    t_env *tmp = data->env;

    while (tmp)
    {
        if (ft_strcmp(tmp->first, key) == 0)
            return (tmp->second);
        tmp = tmp->next;
    }

    return (NULL);
}

/**
 * @brief Envrt değişkenleri içerisinde PATH arıyor ve sonrası döndürerek
 * split ile ":" ayırıyoruz ve / ekleyerek komutların yolunu buluyoruz.
 */

char	*find_path(t_data *data, char **command, int i)
{
	char		*temp;
	char		**paths;
	char		*path_with_slash;
	char		*new_path;

	temp = find_value("PATH", data);
	if (temp == NULL)
		return (NULL);
	paths = ft_split(temp, ':');
	while (paths[i])
	{
		path_with_slash = ft_strjoin(paths[i], "/");
		new_path = ft_strjoin(path_with_slash, command[0]);
		free(path_with_slash);
		if (access(new_path, F_OK) == 0)
		{
			ft_free_str(paths);
			return (new_path);
		}
		free(new_path);
		i++;
	}
	return (ft_free_str(paths), NULL);
}

void	execute_command(char *komut, char **command)
{
	pid_t	child_pid;
	int		status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return ;
	}
	if (child_pid == 0)
	{
		if (execve(komut, command, NULL) == -1)
		{
			ft_error("execve hatası", 0, NULL);
			exit(1);
		}
	}
	else
		waitpid(child_pid, &status, 0);
}

void	command_function(t_data *data, char **command)
{
	char	*komut;

	if (!command[0])
	{
		ft_error("Bellek ayrılma hatası", 0, data);
		return ;
	}
	komut = find_path(data, command, 0);
	if (!komut || !komut[0])
	{
		printf("Komut Bulunamadı.\n");
		//free(komut);
		return ;
	}
	execute_command(komut, command);
	free(komut);
}
