/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:22:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/03 13:29:30 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_spradd_back(t_sprite_list **alst, t_sprite_list *new)
{
	t_sprite_list	*tmp;

	if (!alst || !*alst)
	{
		if (!alst)
			return ;
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_sprclear(t_sprite_list **lst)
{
	t_sprite_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

t_sprite_list	*ft_sprnew(t_sprite *content)
{
	t_sprite_list	*new;

	new = malloc(sizeof(t_sprite_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_swap(t_sprite_list *a, t_sprite_list *b)
{
	t_sprite	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

void	ft_sprsort(t_sprite_list *start)
{
	int				swapped;
	t_sprite_list	*ptr1;
	t_sprite_list	*lptr;

	if (start == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr1 = start;
		while (ptr1->next != NULL)
		{
			if (ptr1->content->distance < ptr1->next->content->distance)
			{
				ft_swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

/*
* void	ft_sprprint(t_sprite_list *lst)
* {
* 	while (lst && lst->next)
* 	{
* 		printf("startx: %d\tendx: %d\theight: %d\toffset_x: %d -> ",
* 			lst->content->start_x, lst->content->end_x,
* 			lst->content->height, lst->content->offset_x);
* 		lst = lst->next;
* 	}
* 	if (lst)
* 	{
* 		printf("startx: %d\tendx: %d\theight: %d\toffset_x: %d\n",
* 			lst->content->start_x, lst->content->end_x,
* 			lst->content->height, lst->content->offset_x);
* 	}
* }
*/