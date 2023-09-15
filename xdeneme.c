#include "library/minishell.h"

int main()
{
    char *str = "asdsaf|>SASDFASDF";
    int i= 0;
    while(str[i])
    {
        if (str[i] == ('|' | '>' | '<' ))
            printf("%c", str[i]);
        i++;
    }
    return (0);
}