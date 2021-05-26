/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:33:17 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/26 19:39:04 by tpetit           ###   ########.fr       */
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

int	get_up_median_value(t_stack *stack, int len, int med, int size)
{
	int	*num_list;
	int	i;
	int j;
	int	temp;
	int	ret;

	num_list = malloc(sizeof(int) * size);
	i = -1;
	j = -1;
	while (++j < len - 1)
	{
		if (stack->content < med)
			num_list[++i] = stack->content;
		stack = stack->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		if (num_list[i] > num_list[i + 1])
		{
			temp = num_list[i];
			num_list[i] = num_list[i + 1];
			num_list[i + 1] = temp;
			i = -1;
		}
	}
	i = -1;
	ret = num_list[size / 2];
	free(num_list);
	printf("%d\n", ret);
	return (ret);
}

static void	solve_swap(t_stack *a)
{
	t_stack	*b;
	int		size;
	int		med;
	int		count;
	int		*groups;
	int		first;
	int		up_med;

	b = NULL;
	first = 1;
	size = 0;
	groups = get_swap_groups(a);
	while (ft_stacksize(a, &size) > 2)
	{
		count = -1;
		med = get_median_value(a, size);
		if (first)
			up_med = get_up_median_value(a, size, med, size / 2);
		while (count < size / 2 - 1 && a && a->next)
		{
			if (a->content < med && (++count || 1))
				push_b(&a, &b, "pb\n");
			else
			{
				if (first && b && b->content < up_med)
					rotate_rotate(&a, &b, "rr\n");
				else
					rotate(&a, "ra\n");
			}
		}
		size = 0;
		first = 0;
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
	}
	return (0);
}
