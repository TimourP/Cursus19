
#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void *test(void *test){
    return "hello";
}

int		main(int argc, char **argv)
{
    char dst[6] = "hello";
    char str[100] = "testee";
    char dst1[6] = "hello";
    char str1[100] = "testee";

    printf("norm : %s\tmy: %s\n", memmove(dst1, str1, 6), ft_memmove(dst, str, 6));
}