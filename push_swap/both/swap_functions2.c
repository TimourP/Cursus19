/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:00:24 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/04 10:50:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
}

void	rotate_rotate(t_stack **a, t_stack **b, const char *to_print)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (to_print)
		write(1, to_print, 3);
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
}

void	r_r_reverse(t_stack **a, t_stack **b, const char *to_print)
{
	r_reverse(a, NULL);
	r_reverse(b, NULL);
	if (to_print)
		write(1, to_print, 4);
}
