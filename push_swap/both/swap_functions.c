/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:58:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/04 11:27:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, const char *to_print)
{
	t_stack	*tmp;

	if (stack && *stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		tmp->next = *stack;
		(*stack) = tmp;
	}
	if (to_print)
		ft_putstr(to_print);
}

void	swap_swap(t_stack **a, t_stack **b, const char *to_print)
{
	swap(a, NULL);
	swap(b, NULL);
	if (to_print)
		ft_putstr(to_print);
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
		ft_putstr(to_print);
}
