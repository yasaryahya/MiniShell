/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int pipe_command(char** commands)
{
    // Komutlar bir dizi olarak verilir.
    if (!commands) {
        return -1;
    }

    // Her komut için bir işlem oluşturulur.
    pid_t pids[count(commands)];
    int fds[2][count(commands) - 1];
    for (int i = 0; i < count(commands); i++)
    {
        if (pipe(fds[i % 2]) < 0) {
            return -1;
        }

        pids[i] = fork();
        if (pids[i] < 0) {
            return -1;
        }

        if (pids[i] == 0) {
            // Arka planda çalışan işlem
            if (i > 0) {
                dup2(fds[(i - 1) % 2][0], STDIN_FILENO);
                close(fds[(i - 1) % 2][0]);
            }

            if (i < count(commands) - 1) {
                dup2(fds[i % 2][1], STDOUT_FILENO);
                close(fds[i % 2][1]);
            }

            execvp(commands[i], commands + i);
            exit(1);
        }
    }

    // Tüm işlemler tamamlanana kadar bekleyin.
    for (int i = 0; i < count(commands); i++) {
        waitpid(pids[i], NULL, 0);
    }

    // Hataları işleyin.
    for (int i = 0; i < count(commands); i++) {
        int status;
        waitpid(pids[i], &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            return -1;
        }
    }

    return 0;
}

int main()
{
    char* commands[] = {"ls -al", "> output.txt", "wc -l output.txt"};

    int ret = pipe_command(commands);
    if (ret < 0)
    {
        perror("pipe_command");
        return 1;
    }
    return 0;
}

*/