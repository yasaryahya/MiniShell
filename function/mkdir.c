
#include "../library/minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int ft_mkdir(t_data data) 
{
    if (mkdir(data.arg[1], 0777) == 0) {
        return 0; // Başarı durumu
    } else {
        ft_error("createDirectory", 0);
        return -1; // Hata durumu
    }
}