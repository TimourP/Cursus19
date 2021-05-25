/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:00:24 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 18:04:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	g_swap_count2 = 0;

void	rotate(t_stack **stack, const char *to_print)
{
	t_stack	*start;
	t_stack	*temp;

	if (stack && *stack && (*stack)->next)
	{
		start = (*stack)->next;
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = *stack;
		(*stack)->next = NULL;
		*stack = start;
	}
	if (to_print)
		write(1, to_print, 3);
	g_swap_count2++;
}

void	rotate_rotate(t_stack **a, t_stack **b, const char *to_print)
{
	rotate(a, to_print);
	rotate(b, to_print);
	if (to_print)
		write(1, to_print, 3);
	g_swap_count2--;
}

void	r_reverse(t_stack **stack, const char *to_print)
{
	t_stack	*start;
	t_stack	*temp;

	if (stack && *stack && (*stack)->next)
	{
		start = *stack;
		while (start->next)
		{
			if (start->next->next == NULL)
				temp = start;
			start = start->next;
		}
		if (temp && temp->next)
			temp->next = NULL;
		start->next = *stack;
		*stack = start;
	}
	if (to_print)
		write(1, to_print, 4);
	g_swap_count2++;
}

void	r_r_reverse(t_stack **a, t_stack **b, const char *to_print)
{
	r_reverse(a, to_print);
	r_reverse(b, to_print);
	if (to_print)
		write(1, to_print, 4);
	g_swap_count2--;
}

int	print_count2(void)
{
	return (g_swap_count2);
}
