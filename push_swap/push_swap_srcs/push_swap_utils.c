/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 09:01:43 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 15:58:12 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_median_value_loop(int *num_list, int len)
{
	int	i;
	int	temp;

	i = -1;
	while (++i < len - 1)
	{
		if (num_list[i] > num_list[i + 1])
		{
			temp = num_list[i];
			num_list[i] = num_list[i + 1];
			num_list[i + 1] = temp;
			i = -1;
		}
	}
}

int	get_median_value(t_stack *stack, int len, t_stack *free_on_error)
{
	int	*num_list;
	int	i;
	int	ret;

	num_list = malloc(sizeof(int) * len);
	if (!num_list && 0)
	{
		if (free_on_error)
			ft_stackclear(&free_on_error);
		exit_message(MALLOC_ERROR, &stack);
	}
	i = -1;
	while (i < len - 1)
	{
		num_list[++i] = stack->content;
		stack = stack->next;
	}
	get_median_value_loop(num_list, len);
	ret = num_list[len / 2];
	free(num_list);
	return (ret);
}

int	*get_swap_groups(t_stack *a)
{
	int	*groups;
	int	size;
	int	stack_size;
	int	i;

	size = 0;
	stack_size = 0;
	ft_stacksize(a, &stack_size);
	while (stack_size > 3)
	{
		stack_size -= stack_size / 2;
		size++;
	}
	groups = malloc(sizeof(int) * (size + 1));
	if (!groups)
		exit_message(MALLOC_ERROR, &a);
	i = -1;
	stack_size = ft_stacksize(a, &stack_size);
	while (++i < size)
	{
		groups[size - i - 1] = stack_size / 2;
		stack_size = stack_size - groups[size - i - 1];
	}
	groups[i] = -1;
	return (groups);
}

static void	swap_med_simple_loop(t_stack **a, t_stack **b,
	int *groups, int current)
{
	int	med;
	int	push;
	int	count;

	med = get_median_value(*b, groups[current], *a);
	count = 0;
	push = 0;
	while (count < 1 + (int)(groups[current] >= 5))
	{
		if ((*b)->content > med && (++ count))
			push_a(a, b, "pa\n");
		else if (++push)
			rotate(b, "rb\n");
	}
	if ((*a) && (*a)->next && (*a)->content > (*a)->next->content)
		swap(a, "sa\n");
	while (--push > -1)
		r_reverse(b, "rrb\n");
	groups[current] = groups[current] - 1 - (int)(groups[current] >= 5);
}

void	swap_med_simple(t_stack **a, t_stack **b, int *groups, int current)
{
	while (groups[current] != 0)
	{
		if (groups[current] == 1)
		{
			push_a(a, b, "pa\n");
			groups[current] = 0;
		}
		else if (groups[current] == 2)
		{
			if ((*b)->content < (*b)->next->content)
				swap(b, "sb\n");
			push_a(a, b, "pa\n");
			push_a(a, b, "pa\n");
			groups[current] = 0;
		}
		else if (groups[current] == 3)
			swap_med_simple_three(a, b, groups, current);
		else
			swap_med_simple_loop(a, b, groups, current);
	}
}
