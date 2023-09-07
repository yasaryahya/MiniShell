
/*
#include <stdio.h>
#include <stdlib.h>

// Çevresel değişkenleri tutmak için kullanılacak struct
struct t_env {
    char *name;
    char *value;
    struct t_env *next;
};

// Yeni bir çevresel değişken ekler
struct t_env *addVariable(struct t_env *head, char *name, char *value)
{
    struct t_env *newVar;
	newVar = (struct t_env *)malloc(sizeof(struct t_env));
    if (newVar == NULL) {
        perror("Bellek tahsis hatası");
        exit(EXIT_FAILURE);
    }

    newVar->name = name;
    newVar->value = value;
    newVar->next = head;

    return newVar;
}

// Çevresel değişkenleri görüntüler
void printVariables(struct t_env *head)
{
    struct t_env *current = head;
    while (current != NULL)
	{
        printf("%s=%s\n", current->name, current->value);
        current = current->next;
    }
}

int main(int argc, char *argv[], char *envp[]) {
    // Çevresel değişkenleri tutacak olan başlangıç düğümü (head)
    struct t_env *envList = NULL;

    // envp dizisini kullanarak çevresel değişkenleri structa ekleyin
    for (int i = 0; envp[i] != NULL; i++) {
        char *envVar = envp[i];
        char *name = strtok(envVar, "=");
        char *value = strtok(NULL, "=");
        envList = addVariable(envList, name, value);
    }

    // Çevresel değişkenleri görüntüle
    printVariables(envList);

    // Belleği temizle
    while (envList != NULL) {
        struct t_env *temp = envList;
        envList = envList->next;
        free(temp);
    }

    return 0;
}



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
*/
