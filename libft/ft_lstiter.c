/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:16:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/18 17:17:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list *tmp;

	tmp = lst;
	while (tmp && tmp->next)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
	if (tmp)
		f(tmp->content);
}