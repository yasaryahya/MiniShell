#include "../library/minishell.h"
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h> // fork, execve, waitpid için gerekli

void ft_free_str(char **str)
{
    int i = 0;

    if (!str)
        return;
    
    while (str[i])
    {
        free(str[i]);
        str[i] = NULL; // Pointer'ı NULL olarak ayarlayın
        i++;
    }
    
    free(str);
    str = NULL;
}

char *find_value(char *key, t_data *data)
{
    int i = 0;

    while (data->envrt[i])
    {
        if (ft_strncmp(data->envrt[i], key, ft_strlen(key)) == 0)
        {
            // "PATH=" ifadesini atlayarak PATH değerini döndürüyoruz
            return (data->envrt[i] + ft_strlen(key));
        }
        i++;
    }
    
    return (NULL); // Belirtilen anahtarı bulamazsak NULL döndürüyoruz
}

char *find_path(char *cmdline, t_data *data)
{
    int i = 0;
    char *temp;
    char *new_path;
    char **paths;
    struct stat a;

    temp = find_value("PATH", data);
    paths = ft_split(temp, ':');
    
    while (paths[i])
    {
        char *path_with_slash = ft_strjoin(paths[i], "/");
        new_path = ft_strjoin(path_with_slash, cmdline);
        
        free(path_with_slash);

        if (stat(new_path, &a) == 0)
        {
            ft_free_str(paths);
            return (new_path);
        }
        
        free(new_path);
        i++;
    }
    
    ft_free_str(paths);
    return (NULL);
}

void command(t_data *data, char **command)
{
    char *cmd = ft_strdup(command[0]);
    
    if (cmd == NULL)
    {
        ft_error("Bellek ayrılma hatası", 0);
        return;
    }

    char *komut = find_path(cmd, data);

    if (komut == NULL || strcmp(komut, "") == 0)
    {
        printf("Komut Bulunamadı.\n");
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
        if (execve(komut, command, NULL) == -1)
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
    printf("\n");
}