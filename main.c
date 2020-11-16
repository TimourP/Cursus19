
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

int		main(int argc, char **argv)
{
    char dst[100];
    char src[100] = "comment ca va";
    printf("%s\n", ft_memcpy(dst, src, 5));
    printf("%s\n", dst);
}