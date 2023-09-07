/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyasar <yyasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 02:41:59 by yyasar            #+#    #+#             */
/*   Updated: 2023/09/07 06:45:03 by yyasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/minishell.h"

/*
void ft_env(t_data *base)
{
    int i;
    int j;

    if (base->env && base->env->data) // Bellek bölgesi ve veri kontrolü
    {
        i = 0;
        while (base->env->data[i])
        {
            j = 0;
            while (base->env->data[i][j] != '\0')
            {
                write(1, &base->env->data[i][j], 1);
                j++;
            }
            printf("\n");
            i++;
        }
    }
    else
    {
        ft_error("ft_env: Geçersiz veri veya bellek hatası", 0);
    }
}*/

	
	
	/*
	t_env	*tmp;

	tmp = base->env;
	while (tmp != NULL)
	{
		if (tmp->data[1] != NULL)
		{
			ft_putstr_fd(tmp->data[0], 1);
			write(1, "=", 1);
			ft_putstr_fd(tmp->data[1], 1);
			write(1, "\n", 1);
		}
		else if (tmp->is_env_equal && tmp->data[1] == NULL)
		{
			ft_putstr_fd(tmp->data[0], 1);
			write(1, "=\n", 2);
		}
		tmp = tmp->next;
	}
	return;
	*/

/*
void	free_list(void)
{
	t_env	*tmp;

	while (data->env != NULL)
	{
		free(data->env->content);
		tmp = data->env;
		data->env = data->env->next;
		free(tmp);
	}
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Çevre değişkenlerini temsil etmek için bir düğüm yapısı
struct EnvNode {
    char *data;
    struct EnvNode *next;
};

// Bağlı liste için başlangıç düğümü
struct EnvNode *envList = NULL;

// Yeni bir çevre değişkeni düğümü oluşturma
struct EnvNode *createNode(char *data) {
    struct EnvNode *newNode = (struct EnvNode *)malloc(sizeof(struct EnvNode));
    if (newNode) {
        newNode->data = strdup(data); // Veriyi kopyala
        newNode->next = NULL;
    }
    return newNode;
}

// Bağlı listeye yeni bir çevre değişkeni düğümü ekleme
void appendNode(char *data) {
    struct EnvNode *newNode = createNode(data);
    if (!newNode) {
        fprintf(stderr, "Hata: Bellek ayrılamadı\n");
        exit(1);
    }
    
    if (!envList) {
        envList = newNode;
    } else {
        struct EnvNode *temp = envList;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Bağlı listeyi temizleme (belleği serbest bırakma)
void clearEnvList() {
    struct EnvNode *current = envList;
    while (current) {
        struct EnvNode *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    envList = NULL;
}

int main(int argc, char **argv, char **envp) {
    // envp içindeki çevre değişkenlerini bağlı listeye kopyala
    for (int i = 0; envp[i] != NULL; i++) {
        appendNode(envp[i]);
    }

    // Bağlı listeyi yazdırma
    struct EnvNode *current = envList;
    while (current) {
        printf("%s\n", current->data);
        current = current->next;
    }

    // Bağlı listeyi temizleme
    clearEnvList();

    return 0;
}

*/