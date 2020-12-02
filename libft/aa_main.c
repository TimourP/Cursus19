#include "libft.h"
#include <stdio.h>

int main(void)
{
    t_list *nd1 = ft_lstnew("hello");
    ft_lstiter(nd1, NULL);
    return 0;
}