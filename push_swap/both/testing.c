/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:05:13 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/12 18:31:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	printf("    a    |    b\n");
	printf("-------------------\n");
	while (a || b)
	{
		if (a)
		{
			if (b)
			{
				printf("%5d", a->content);
				printf("    |");
			}
			else
				printf("%5d    |\n", a->content);
			a = a->next;
		}
		if (b)
		{
			printf("%5d\n", b->content);
			b = b->next;
		}
	}
}