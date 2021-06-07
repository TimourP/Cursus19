/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:36:12 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 15:40:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_p(t_stack *stack, int value)
{
	int	bigger_than;

	bigger_than = 1;
	while (stack)
	{
		if (stack->content < value)
			bigger_than++;
		stack = stack->next;
	}
	return (bigger_than);
}

void	tiny_swap(t_stack **a)
{
	if (get_p(*a, (*a)->content) == 1 && get_p(*a, (*a)->next->content)
		== 3 && get_p(*a, (*a)->next->next->content) == 2)
	{
		r_reverse(a, "rra\n");
		swap(a, "sa\n");
	}
	else if (get_p(*a, (*a)->content) == 2 && get_p(*a, (*a)->next->content)
		== 1 && get_p(*a, (*a)->next->next->content) == 3)
		swap(a, "sa\n");
	else if (get_p(*a, (*a)->content) == 2 && get_p(*a, (*a)->next->content)
		== 3 && get_p(*a, (*a)->next->next->content) == 1)
		r_reverse(a, "rra\n");
	else if (get_p(*a, (*a)->content) == 3 && get_p(*a, (*a)->next->content)
		== 1 && get_p(*a, (*a)->next->next->content) == 2)
		rotate(a, "ra\n");
	else
	{
		swap(a, "sa\n");
		r_reverse(a, "rra\n");
	}
}
