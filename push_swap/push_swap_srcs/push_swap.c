/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:33:17 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 14:19:42 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int *remake_groups(int *groups, int count)
{
	int i;
	int i_g;
	int size;
	int	*new_groups;

	i = -1;
	size = 0;
	while (groups[++i] != -1)
		if (groups[i])
			size++;
	new_groups = malloc(sizeof(int) * (size + 2));
	new_groups[0] = count;
	i_g = -1;
	i = 0;
	while (groups[++i_g] != -1)
		if (groups[i_g])
			new_groups[++i] = groups[i_g];
	new_groups[i + 1] = -1;
	free(groups);
	return (new_groups);
}

static void	re_swap(t_stack **a, t_stack **b,  int **groups, int *current)
{
	int	len;
	int med;
	int i;
	int push;
	int count;

	len = (*groups)[*current];
	(*groups)[*current] =  (*groups)[*current] - len / 2 + !(len%2);
	med = get_median_value(*b, len);
	i = -1;
	push = 0;
	while (++i < len)
	{
		if ((*b)->content > med)
			push_a(a, b, "pa\n");
		else
		{
			push++;
			rotate(b, "rb\n");
		}
	}
	i = -1;
	while (++i < push)
		r_reverse(b, "rrb\n");
	len = len / 2 - !(len%2);
	while (len > 2)
	{
		count = 0;
		med = get_median_value(*a, len);
		push = 0;
		while (count < len / 2 && *a && (*a)->next)
		{
			if ((*a)->content < med)
			{
				push_b(a, b, "pb\n");
				count++;
			}
			else
			{
				rotate(a, "ra\n");
				push++;
			}
		}
		i = -1;
		while (++i < push)
			r_reverse(a, "rra\n");
		len -= count;
		*groups = remake_groups(*groups, count);
	}
	if ((*a) && (*a)->next && (*a)->content > (*a)->next->content)
		swap(a, "sa\n");
	*current = 0;
}

static void	solve_swap2(t_stack *a, t_stack *b, int *groups)
{
	int	current_group;

	current_group = 0;
	if (a && a->next && a->content > a->next->content)
		swap(&a, "sa\n");
	while (groups[current_group] != -1)
	{
		if (groups[current_group] > 6)
		{
			re_swap(&a, &b, &groups, &current_group);
		}
		while (groups[current_group] <= 6 && groups[current_group] != -1)
		{
			swap_med_simple(&a, &b, groups, current_group);
			current_group++;
		}
	}
	free(groups);
	ft_stackclear(&a);
	ft_stackclear(&b);
}

static void	solve_swap(t_stack *a)
{
	t_stack	*b;
	int		size;
	int		med;
	int		count;
	int		*groups;

	b = NULL;
	size = 0;
	groups = get_swap_groups(a);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		print_errors(ARGS_NUMBER);
	else if (!check_args(argc, argv))
		print_errors(ARGS_TYPE_ERROR);
	else
	{
		fill_struct(argc, argv, &a);
		solve_swap(a);
		print_count();
	}
	return (0);
}
