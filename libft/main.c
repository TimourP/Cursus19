#include "libft.h"
#include <stdio.h>

int main(void)
{
    char test[100] = "hello comment allez vous ?";
    char **f;
    int i;

    f = ft_split(test, ' ');
    i = -1;
    while (f[++i])
    {
        printf("%s\n", f[i]);
    }
}