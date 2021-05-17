/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:33:17 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/17 18:24:05 by tpetit           ###   ########.fr       */
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
	while (stack)
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

static void	solve_swap2(t_stack *a, t_stack *b, const int *groups)
{
	int	current_group;

	current_group = 0;
	if (a && a->next && a->content > a->next->content)
		swap(&a);
	if (groups[current_group] == 1)
		push_a(&a, &b);
	if (groups[current_group] == 2)
	{
		if (b->content < b->next->content)
			swap(&b);
		push_a(&a, &b);
		push_a(&a, &b);
	}
	current_group--;
	while (groups[++current_group] != -1)
	{
		printf("%d\n", groups[current_group]);
	}
	print_stack(a, b);
}

static void	solve_swap(t_stack *a)
{
	t_stack	*b;
	int		size;
	int		med;
	int		count;
	const int	*groups = get_swap_groups(a);

	b = NULL;
	size = 0;
	get_swap_groups(a);
	while (ft_stacksize(a, &size) > 2)
	{
		count = -1;
		med = get_median_value(a, size);
		while (count < size / 2 - 1 && a && a->next)
		{
			if (a->content < med)
			{
				push_b(&a, &b);
				count++;
			}
			else
				rotate(&a);
		}
		size = 0;
	}
	print_stack(a, b);
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
		solve_swap(a);
	}
	return (0);
}