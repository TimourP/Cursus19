/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:57:58 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 16:00:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	b_pos(t_stack *b, int id, int len)
{
	int		c_val;
	int		i;
	int		bigger_than;
	t_stack	*tmp;

	c_val = b->content;
	i = -1;
	tmp = b;
	while (++i < id + 1)
	{
		c_val = tmp->content;
		tmp = tmp->next;
	}
	bigger_than = 1;
	i = -1;
	while (b && ++i < len)
	{
		if (b->content < c_val)
			bigger_than++;
		b = b->next;
	}
	return (bigger_than);
}

static void	swap_med_simple_three_end2(t_stack **a, t_stack **b)
{
	if (b_pos(*b, 0, 3) == 3 && b_pos(*b, 1, 3)
		== 1 && b_pos(*b, 2, 3) == 2)
	{
		push_a(a, b, "pa\n");
		swap(b, "sb\n");
		push_a(a, b, "pa\n");
		push_a(a, b, "pa\n");
	}
	else
	{
		push_a(a, b, "pa\n");
		push_a(a, b, "pa\n");
		push_a(a, b, "pa\n");
	}
}

static void	swap_med_simple_three_end(t_stack **a, t_stack **b)
{
	if (b_pos(*b, 0, 3) == 2 && b_pos(*b, 1, 3)
		== 1 && b_pos(*b, 2, 3) == 3)
	{
		push_a(a, b, "pa\n");
		swap(b, "sb\n");
		push_a(a, b, "pa\n");
		swap(a, "sa\n");
		push_a(a, b, "pa\n");
	}
	else if (b_pos(*b, 0, 3) == 2 && b_pos(*b, 1, 3)
		== 3 && b_pos(*b, 2, 3) == 1)
	{
		swap(b, "sb\n");
		push_a(a, b, "pa\n");
		push_a(a, b, "pa\n");
		push_a(a, b, "pa\n");
	}
	else
		swap_med_simple_three_end2(a, b);
}

void	swap_med_simple_three(t_stack **a, t_stack **b,
	int *groups, int current)
{
	if (b_pos(*b, 0, 3) == 1 && b_pos(*b, 1, 3)
		== 2 && b_pos(*b, 2, 3) == 3)
	{
		push_a(a, b, "pa\n");
		swap(b, "sb\n");
		push_a(a, b, "pa\n");
		swap(a, "sa\n");
		push_a(a, b, "pa\n");
		swap(a, "sa\n");
	}
	else if (b_pos(*b, 0, 3) == 1 && b_pos(*b, 1, 3)
		== 3 && b_pos(*b, 2, 3) == 2)
	{
		swap(b, "sb\n");
		push_a(a, b, "pa\n");
		swap(b, "sb\n");
		push_a(a, b, "pa\n");
		push_a(a, b, "pa\n");
	}
	else
		swap_med_simple_three_end(a, b);
	groups[current] = 0;
}
