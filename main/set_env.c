#include "../library/minishell.h"

t_env *envList = NULL;

t_env *createEnvNode(char *str)
{
    t_env *newNode = (t_env *)malloc(sizeof(t_env));
    if (newNode)
    {
        newNode->data = ft_strdup(str);
        newNode->is_env_equal = (ft_strncmp(str, "=", 1) == 0);
        newNode->next = NULL;
        //newNode->prev = NULL;
    }
    return newNode;
}

void    appendEnvNode(char *str)
{
    t_env *newNode = createEnvNode(str);
    if (!newNode)
        ft_error("set_arg/ bellek hatası", 1);
    if (!envList)
        envList = newNode;
    else
    {
        t_env *temp = envList;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        //newNode->prev = temp;
    }
}

void    clearEnvList()
{
    t_env *current = envList;
    while (current) {
        t_env *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    envList = NULL;
}

int set_env(char **envp)
{
    int i;

    i = 0;
    while (envp[i] != NULL)
        appendEnvNode(envp[i++]);
    return (1);
}

void    env_print(void)
{
    t_env *current = envList;
        while (current)
        {
            printf("%s\n", current->data);
            current = current->next;
        }
    return;
}