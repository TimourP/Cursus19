
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
    char dst[100];
    char src1[100] = "COMMENT";
    char src2[100] = "comment";
    printf("%s\n", ft_strmapi(src1, test));
}