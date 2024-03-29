/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:33:17 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/08 19:23:00 by tpetit           ###   ########.fr       */
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
	if (!check_sort(a) && ft_stacksize(a, NULL) == 2)
		swap(&a, "sa\n");
	else if (!check_sort(a) && ft_stacksize(a, NULL) == 3)
		tiny_swap(&a);
	while (groups[current_group] != -1)
	{
		if (groups[current_group] > 6)
			re_swap(&a, &b, &groups, &current_group);
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

static void	solve_swap_loop(int mucf[4], t_stack **a, t_stack **b)
{
	if ((*a)->content < mucf[0] && (++mucf[2] || 1))
		push_b(a, b, "pb\n");
	else
	{
		if (mucf[3] && *b && (*b)->content < mucf[1])
			rotate_rotate(a, b, "rr\n");
		else
			rotate(a, "ra\n");
	}
}

static void	solve_swap(t_stack *a)
{
	t_stack	*b;
	int		size;
	int		mucf[4];
	int		*groups;

	b = NULL;
	mucf[3] = 1;
	size = 0;
	groups = get_swap_groups(a);
	while (ft_stacksize(a, &size) > 3)
	{
		mucf[2] = -1;
		mucf[0] = get_median_value(a, size, NULL);
		if (mucf[3])
			mucf[1] = get_up_median_value(a, size, mucf[0], size / 2);
		while (mucf[2] < size / 2 - 1 && a && a->next)
			solve_swap_loop(mucf, &a, &b);
		size = 0;
		mucf[3] = 0;
	}
	solve_swap2(a, b, groups);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc <= 1)
		return (0);
	else if (!check_args(argc, argv))
		print_errors(ARGS_TYPE_ERROR);
	else
	{
		fill_struct(argc, argv, &a);
		if (check_sort(a))
			ft_stackclear(&a);
		else if (ft_stacksize(a, NULL) != 3)
			solve_swap(a);
		else
		{
			tiny_swap(&a);
			ft_stackclear(&a);
		}
	}
	return (0);
}
