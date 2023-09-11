#include "../library/minishell.h"

t_env   *esitsayisi(t_env *newNode, int count, int len, char *str)
{
    if (newNode)
    {
        if (count == 1)
        {
            newNode->first = ft_substr(str, 0, len);
            newNode->second = ft_substr(str, len, (ft_strlen(str)-len));
        }
        else if (count > 1)
        {   
            char *s = ft_strjoin("=\"", (ft_strchr(str, 61)+1));
            newNode->first = ft_substr(str, 0, len);
            newNode->second = ft_strjoin(s, "\"");
            free(s);
        }
        else
        {
            newNode->first = ft_strdup(str);
            newNode->second = ft_strdup("");
        }
        newNode->data = ft_strdup(str);
        newNode->next = NULL;
    }
    return newNode;
}

t_env   *createEnvNode(char *str)
{
    int len = 0;
    int count = 0;
    while (str[len])
    {
        if (str[len] == '=')
            count++;
        len++;
    }
    len = 0;
    while (str[len])
    {
        if (str[len] == '=')
            break;
        len++;
    }
    t_env *newNode = (t_env *)malloc(sizeof(t_env));
    return(esitsayisi(newNode, count, len, str));
}

void    appendEnvNode(char *str, t_env **envList)
{
    t_env *newNode = createEnvNode(str);
    if (!newNode)
        ft_error("set_env/ bellek hatası", 1);
    if (!(*envList))
        *envList = newNode;
    else
    {
        t_env *temp = *envList;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

int set_env(t_data *data)
{
    int i;

    i = -1;
    t_env *envList = NULL;
    while (data->envrt[++i] != NULL)
        appendEnvNode(data->envrt[i], &envList);
    data->env = envList;
    return (1);
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