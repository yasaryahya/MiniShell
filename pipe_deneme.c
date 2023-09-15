/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_deneme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:21:42 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/15 02:04:01 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
/*
int pipe_command(char** arg)
{
    // Komutlar bir dizi olarak verilir.
    if (!arg)
        return -1;
    // Her komut için bir işlem oluşturulur.
    pid_t pids[count(arg)];
    int fds[2][count(arg) - 1];
    for (int i = 0; i < count(arg); i++)
	{
        if (pipe(fds[i % 2]) < 0)
            return -1;
        pids[i] = fork();
        if (pids[i] < 0)
            return -1;
        if (pids[i] == 0)
		{
            // Arka planda çalışan işlem
            if (i > 0)
			{
                dup2(fds[(i - 1) % 2][0], STDIN_FILENO);
                close(fds[(i - 1) % 2][0]);
            }
            if (i < count(arg) - 1)
			{
                dup2(fds[i % 2][1], STDOUT_FILENO);
                close(fds[i % 2][1]);
            }
            execvp(arg[i], arg + i);
            exit(1);
        }
    }

    // Tüm işlemler tamamlanana kadar bekleyin.
    for (int i = 0; i < count(arg); i++)
	{
        waitpid(pids[i], NULL, 0);
    }

    // Hataları işleyin.
    for (int i = 0; i < count(arg); i++)
	{
        int status;
        waitpid(pids[i], &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            return -1;
    }
    return 0;
}


int main()
{
    char* arg[] = {"ls -al", "> output.txt", "wc -l output.txt"};

    int ret = pipe_command(arg);
    if (ret < 0)
	{
        perror("pipe_command");
        return 1;
    }
    return 0;
}
*/