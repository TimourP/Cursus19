/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:58:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 18:01:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	g_swap_count = 0;

void	swap(t_stack **stack, const char *to_print)
{
	t_stack	*tmp;
	t_stack	*start;

	if (stack && *stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		(*stack) = tmp;
	}
	if (to_print)
		write(1, to_print, 3);
	g_swap_count++;
}

void	swap_swap(t_stack **a, t_stack **b, const char *to_print)
{
	swap(a, to_print);
	swap(b, to_print);
	if (to_print)
		write(1, to_print, 3);
	g_swap_count--;
}

void	push_a(t_stack **a, t_stack **b, const char *to_print)
{
	t_stack	*temp;

	if (!a || !b || !*b)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	(*a) = (*b);
	(*b) = temp;
	if (to_print)
		write(1, to_print, 3);
	g_swap_count++;
}

void	push_b(t_stack **a, t_stack **b, const char *to_print)
{
	t_stack	*temp;

	if (!a || !b || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (to_print)
		write(1, to_print, 3);
	g_swap_count++;
}

int	print_count(void)
{
	return (g_swap_count);
}
