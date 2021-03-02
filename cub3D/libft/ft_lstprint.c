/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:06:57 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/02 10:29:21 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstprint(t_list *lst)
{
	while (lst && lst->next)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	if (lst)
		printf("%s\n", lst->content);
}
