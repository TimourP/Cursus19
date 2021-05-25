/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:58:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 10:51:37 by tpetit           ###   ########.fr       */
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
	g_swap_count++;
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
	g_swap_count++;
}

void	rotate_rotate(t_stack **a, t_stack **b, const char *to_print)
{
	rotate(a, to_print);
	rotate(b, to_print);
	if (to_print)
		write(1, to_print, 3);
	g_swap_count++;
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
	g_swap_count++;
}

void	r_r_reverse(t_stack **a, t_stack **b, const char *to_print)
{
	r_reverse(a, to_print);
	r_reverse(b, to_print);
	if (to_print)
		write(1, to_print, 4);
	g_swap_count++;
}

void	print_count(void)
{
	printf("%d\n", g_swap_count);
}
