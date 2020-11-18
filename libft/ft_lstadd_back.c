/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:59:25 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/18 17:01:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *tmp;

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