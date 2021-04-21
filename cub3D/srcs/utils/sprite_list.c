/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:22:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/21 11:00:00 by tpetit           ###   ########.fr       */
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

void	ft_sprprint(t_sprite_list *lst)
{
	while (lst && lst->next)
	{
		printf("startx: %d\tendx: %d\theight: %d\toffset_x: %d -> ",
			lst->content->start_x, lst->content->end_x, lst->content->height, lst->content->offset_x);
		lst = lst->next;
	}
	if (lst)
	{
		printf("startx: %d\tendx: %d\theight: %d\toffset_x: %d\n",
			lst->content->start_x, lst->content->end_x, lst->content->height, lst->content->offset_x);
	}
}
