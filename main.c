
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

char test(unsigned int i, char c)
{
    if (c < 90)
    {
        return c + 32;
    }
    return c;
}

int		main(int argc, char **argv)
{
    printf("%s\n", ft_strjoin("hello", ""));
}