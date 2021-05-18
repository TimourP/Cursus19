/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:33:17 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/18 10:58:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_median_value(t_stack *stack, int len)
{
	int	*num_list;
	int i;
	int temp;

	num_list = malloc(sizeof(int) * len);
	i = -1;
	while (i < len - 1)
	{
		num_list[++i] = stack->content;
		stack = stack->next;
	}
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
	return (num_list[len / 2]);
}

static int	*get_swap_groups(t_stack *a)
{
	int	*groups;
	int	size;
	int	stack_size;
	int i;

	size = 0;
	stack_size = 0;
	ft_stacksize(a, &stack_size);
	while (stack_size > 2)
	{
		stack_size = stack_size - stack_size / 2;
		size++;
	}
	groups = malloc(sizeof(int) * (size + 1));
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

static void	swap_med_simple(t_stack **a, t_stack **b, int *groups, int current)
{
	int med;
	int	push;
	int count;

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
		else
		{
			med = get_median_value(*b, groups[current]);
			count = 0;
			push = 0;
			while (count < 1 + (int)(groups[current] >= 5))
			{
				if ((*b)->content > med)
				{
					count++;
					push_a(a, b, "pa\n");
				}
				else
				{
					push++;
					rotate(b, "rb\n");
				}
			}
			if ((*a) && (*a)->next && (*a)->content > (*a)->next->content)
				swap(a, "sa\n");
			while (--push > -1)
				r_reverse(b, "rrb\n");
			groups[current] = groups[current] - 1 - (int)(groups[current] >= 5);
		}
	}
}

static void	solve_swap2(t_stack *a, t_stack *b, int *groups)
{
	int	current_group;

	current_group = 0;
	if (a && a->next && a->content > a->next->content)
		swap(&a, "sa\n");
	current_group--;
	while (groups[++current_group] <= 6 && groups[current_group] != -1)
		swap_med_simple(&a, &b, groups, current_group);
	print_stack(a, b);
}

static void	solve_swap(t_stack *a)
{
	t_stack	*b;
	int		size;
	int		med;
	int		count;
	int	*groups;

	b = NULL;
	size = 0;
	groups = get_swap_groups(a);
	get_swap_groups(a);
	while (ft_stacksize(a, &size) > 2)
	{
		count = -1;
		med = get_median_value(a, size);
		while (count < size / 2 - 1 && a && a->next)
		{
			if (a->content < med)
			{
				push_b(&a, &b, "pb\n");
				count++;
			}
			else
				rotate(&a, "ra\n");
		}
		size = 0;
	}
	solve_swap2(a, b, groups);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		print_errors(ARGS_NUMBER);
	else if (!check_args(argc, argv))
		print_errors(ARGS_TYPE_ERROR);
	else
	{
		fill_struct(argc, argv, &a);
		print_stack(a, b);
		solve_swap(a);
		print_count();
	}
	return (0);
}