/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:37:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/03 20:29:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*remake_groups(int *groups, int count)
{
	int	i;
	int	i_g;
	int	size;
	int	*new_groups;

	i = -1;
	size = 0;
	while (groups[++i] != -1)
		if (groups[i])
			size++;
	new_groups = malloc(sizeof(int) * (size + 2));
	if (!new_groups)
		return (NULL);
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

/*
** lmipc
** len - mediane - i - push - count
*/

static void	re_swap_loop(t_stack **a, t_stack **b, int **groups, int lmipc[5])
{
	lmipc[4] = 0;
	lmipc[1] = get_median_value(*a, lmipc[0], *b);
	lmipc[3] = 0;
	while (lmipc[4] < lmipc[0] / 2 && *a && (*a)->next)
	{
		if ((*a)->content < lmipc[1] && ++lmipc[4])
			push_b(a, b, "pb\n");
		else if (++lmipc[3])
			rotate(a, "ra\n");
	}
	lmipc[2] = -1;
	while (++lmipc[2] < lmipc[3])
		r_reverse(a, "rra\n");
	lmipc[0] -= lmipc[4];
	*groups = remake_groups(*groups, lmipc[4]);
	if (!(*groups))
	{
		ft_stackclear(b);
		exit_message(MALLOC_ERROR, a);
	}
}

void	re_swap(t_stack **a, t_stack **b, int **groups, int *current)
{
	int	lmipc[5];

	lmipc[0] = (*groups)[*current];
	(*groups)[*current] = (*groups)[*current] - lmipc[0] / 2 + !(lmipc[0] % 2);
	lmipc[1] = get_median_value(*b, lmipc[0], *a);
	lmipc[3] = 0;
	lmipc[2] = 0;
	while (lmipc[2] < lmipc[0] / 2 - !(lmipc[0] % 2))
	{
		if ((*b)->content > lmipc[1] && ++lmipc[2])
			push_a(a, b, "pa\n");
		else if (++lmipc[3])
			rotate(b, "rb\n");
	}
	lmipc[2] = -1;
	while (++lmipc[2] < lmipc[3])
		r_reverse(b, "rrb\n");
	lmipc[0] = lmipc[0] / 2 - !(lmipc[0] % 2);
	while (lmipc[0] > 2)
		re_swap_loop(a, b, groups, lmipc);
	if ((*a) && (*a)->next && (*a)->content > (*a)->next->content)
		swap(a, "sa\n");
	*current = 0;
}

static void	get_up_median_loop(int *num_list, int i)
{
	int	temp;

	temp = num_list[i];
	num_list[i] = num_list[i + 1];
	num_list[i + 1] = temp;
	i = -1;
}

int	get_up_median_value(t_stack *stack, int len, int med, int size)
{
	int	*num_list;
	int	i;
	int	j;
	int	ret;

	num_list = malloc(sizeof(int) * size);
	if (!num_list)
		exit_message(MALLOC_ERROR, &stack);
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
		if (num_list[i] > num_list[i + 1])
			get_up_median_loop(num_list, i);
	i = -1;
	ret = num_list[size / 2];
	free(num_list);
	return (ret);
}
