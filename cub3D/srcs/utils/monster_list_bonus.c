/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:45:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/28 19:47:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	ft_monster_add_back(t_monster_list **alst, t_monster_list *new)
{
	t_monster_list	*tmp;

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

void	ft_monster_clear(t_monster_list **lst)
{
	t_monster_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

t_monster_list	*ft_monster_new(t_monster *content)
{
	t_monster_list	*new;

	new = malloc(sizeof(t_monster_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_monsterprint(t_monster_list *lst)
{
	while (lst && lst->next)
	{
		printf("x: %f\ty%f -> ",
			lst->content->x, lst->content->y);
		lst = lst->next;
	}
	if (lst)
	{
		printf("x: %f\ty%f\n",
			lst->content->x, lst->content->y);
	}
}
