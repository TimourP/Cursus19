
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    printf("%s\n", ft_strtrim("   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !", " \t\n"));
}