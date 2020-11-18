/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:21:26 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/18 17:31:57 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    int  list_size = ft_lstsize(lst);
    t_list  **render_list;
    t_list  *tmp;

    *render_list = ft_lstnew(lst->content);
    if (!(render_list = malloc(sizeof(t_list*) * list_size)))
        return (NULL);
    tmp = lst;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
        ft_lstadd_back(render_list, f(tmp->content));
	}
	if (tmp)
		ft_lstadd_back(render_list, f(tmp->content));
    return (*render_list);
}