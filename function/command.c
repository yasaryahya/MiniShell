#include "../library/minishell.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h> // fork, execve, waitpid için gerekli

char *find_value(char *key, char **envp)
{
    int i = 0;

    while (envp[i])
    {
        if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0)
            return (envp[i] + ft_strlen(key) + 1);
        i++;
    }
    return ("");
}

char *find_path(char *cmdline, char **envp)
{
    int i = 0;
    char *temp;
    char *new_path;
    char **paths;
    struct stat a;

    temp = find_value("PATH", envp);
    paths = ft_split(temp, ':');
    while (paths[i])
    {
        temp = ft_strjoin(paths[i], "/");
        new_path = ft_strjoin(temp, cmdline);
        free(temp);

        if (stat(new_path, &a) == 0)
        {
            ft_malloc_error(paths);
            return (new_path);
        }
        free(new_path);
        i++;
    }
    ft_malloc_error(paths);
    return (ft_strdup(cmdline));
}


void command(t_data data)
{
    char *cmd = ft_strdup(data.arg[0]); // arg[0] kopyalanıyor
    if (cmd == NULL)
    {
        ft_error("Bellek ayrılma hatası", 0);
        return;
    }

    char *komut = find_path(cmd, data.envrt);

    if (komut == NULL)
    {
        ft_error("Komut bulunamadı", 0);
        free(cmd);
        return;
    }

    // Yeni bir süreç oluştur
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        free(cmd);
        return;
    }

    if (child_pid == 0)
    { // Çocuk süreç
        if (execve(komut, data.arg, NULL) == -1)
        {
            ft_error("execve hatası", 0);
            free(cmd);
            exit(1);
        }
    }
    else
    { // Ebeveyn süreç
        int status;
        waitpid(child_pid, &status, 0);
        free(cmd); // Bellek serbest bırakılıyor
    }
}

