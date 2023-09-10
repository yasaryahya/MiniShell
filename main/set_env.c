#include "../library/minishell.h"

t_env *createEnvNode(char *str)
{
    t_env *newNode = (t_env *)malloc(sizeof(t_env));
    if (newNode)
    {
        newNode->data = ft_strdup(str);
        newNode->next = NULL;
    }
    return newNode;
}

void    appendEnvNode(char *str, t_env *envList)
{
    t_env *newNode = createEnvNode(str);
    if (!newNode)
        ft_error("set_arg/ bellek hatası", 1);
    if (!envList)
        &envList = newNode;
    else
    {
        t_env *temp = envList;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        envList = temp;
    }
}

int set_env(t_data *data, char **envp)
{
    int i;

    i = 0;
    t_env *envList = NULL;
    while (envp[i] != NULL)
        appendEnvNode(envp[i++], envList);
    data->env = envList;
    return (1);
}

void    env_print(t_data *data)
{
    t_env *current = data->env;
        while (current)
        {
            printf("%s\n", current->data);
            current = current->next;
        }
    return;
}

void    clearEnvList(t_data *data)
{
    t_env *current = data->env;
    while (current) {
        t_env *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    current = NULL;
}