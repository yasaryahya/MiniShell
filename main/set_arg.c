#include "../library/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_env *envList = NULL;

t_env *createEnvNode(char *data) {
    t_env *newNode = (t_env *)malloc(sizeof(t_env));
    if (newNode) {
        newNode->data = strdup(data);
        newNode->is_env_equal = (strncmp(data, "=", 1) == 0);
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    return newNode;
}

void appendEnvNode(char *data) {
    t_env *newNode = createEnvNode(data);
    if (!newNode) {
        fprintf(stderr, "Hata: Bellek ayrılamadı\n");
        exit(1);
    }

    if (!envList) {
        envList = newNode;
    } else {
        t_env *temp = envList;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void clearEnvList() {
    t_env *current = envList;
    while (current) {
        t_env *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    envList = NULL;
}

int set_arg(char **envp, int flag) {
    if (flag == 0) {
        clearEnvList(); // Önce envList'i temizle
        for (int i = 0; envp[i] != NULL; i++) {
            appendEnvNode(envp[i]);
        }
    } else if (flag == 1) {
        t_env *current = envList;
        while (current) {
            printf("%s\n", current->data);
            current = current->next;
        }
    }

    return 1;
}