/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:21:26 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/21 18:13:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*render_list;
	t_list	*tmp;

	render_list = lst ? ft_lstnew(f(lst->content)) : 0;
	tmp = lst;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		ft_lstadd_back(&render_list, ft_lstnew(f(tmp->content)));
	}
	return (render_list);
}
