#include "../library/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>


int rm(const char *filename) {
    if (unlink(filename) == 0) {
        printf("'%s' dosyası silindi.\n", filename);
        return 0; // Başarı durumu
    } else {
        perror("unlink");
        return -1; // Hata durumu
    }
}
