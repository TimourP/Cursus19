
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void *test(void *test){
    return "hello";
}

int		main(int argc, char **argv)
{
    t_list *list = ft_lstnew("hella");
    t_list *new_list = ft_lstmap(list, test, test);
    t_list *tmp = new_list;

    while (tmp)
    {
        tmp->next ? printf("%s => ", tmp->content) : printf("%s", tmp->content);
        tmp = tmp->next;
    }
    
}