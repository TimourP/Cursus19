/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:58:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/14 15:19:42 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *tmp;
	t_stack *start;

	if (stack && *stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		(*stack) = tmp;
	}
}

void	swap_swap(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!a || !b || !*b)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	(*a) = (*b);
	(*b) = temp;
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!a || !b || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	rotate(t_stack **stack)
{
	t_stack *start;
	t_stack *temp;

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
}

void	rotate_rotate(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	r_reverse(t_stack **stack)
{
	t_stack *start;
	t_stack *temp;

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
}

void	r_r_reverse(t_stack **a, t_stack **b)
{
	r_reverse(a);
	r_reverse(b);
}