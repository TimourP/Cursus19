/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:33:17 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/26 18:29:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_sort(t_stack *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
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
			if (a->content < med && (++count || 1))
				push_b(&a, &b, "pb\n");
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
		if (!check_sort(a))
			solve_swap(a);
		printf("Count: %d\n", print_count() + print_count2());
	}
	return (0);
}
