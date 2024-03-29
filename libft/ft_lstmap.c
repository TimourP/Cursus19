/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:21:26 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/07 08:29:16 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*render_list;
	t_list	*tmp;
	t_list	*new_element;

	if (!lst || !f || !(new_element = ft_lstnew(f(lst->content))))
		return (NULL);
	render_list = new_element;
	tmp = lst;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (!(new_element = ft_lstnew(f(tmp->content))))
		{
			ft_lstclear(&render_list, del);
			return (NULL);
		}
		ft_lstadd_back(&render_list, new_element);
	}
	return (render_list);
}
