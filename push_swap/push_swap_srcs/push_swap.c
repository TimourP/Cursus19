/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:33:17 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/14 15:55:46 by tpetit           ###   ########.fr       */
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

static void	solve_swap(t_stack *a)
{
	t_stack	*b;
	int		size;
	int		med;
	int		count;

	b = NULL;
	size = 0;
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