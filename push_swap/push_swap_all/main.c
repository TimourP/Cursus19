/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:08:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/26 23:41:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define SWAP_COUNT 10

int count_pa(int int_stack[SWAP_COUNT])
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (++i < SWAP_COUNT)
		if (int_stack[i] == 0)
			count++;
	return (count);
}

static void	execute_move(t_stack **a, t_stack **b, int move)
{
	if (move == 0)
		push_a(a, b, NULL);
	else if (move == 1)
		swap(a, NULL);
	else if (move == 2)
		swap(b, NULL);
	else if (move == 3)
		swap_swap(a, b, NULL);
}

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

void print_moves(int int_stack[SWAP_COUNT], char *poss[4], t_stack **a, t_stack **b)
{
	int i;
	t_stack *tmp;

	i = -1;
	while (++i < SWAP_COUNT)
	{
		if (int_stack[i] != -1)
		{
			printf("%s(%d) ", poss[int_stack[i]], int_stack[i]);
			execute_move(a, b, int_stack[i]);
		}
	}
	tmp = *a;
	printf("> ");
	while (tmp)
	{
		printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	if (check_sort(*a))
		exit(0);
}

int main(void)
{
	int i;
	int j;
	int	swap_count;
	int int_stack[SWAP_COUNT];
	char *poss[4] = {"pa", "sa", "sb", "ss"};
	int id;
	t_stack *a;
	t_stack *b;

	i = -1;
	id = 0;
	swap_count = 4;
	while (++i < SWAP_COUNT)
		int_stack[i] = -1;
	int_stack[0] = 0;
	i = -1;
	j = 0;
	while (int_stack[SWAP_COUNT - 1] != 3)
	{
		int_stack[id]++;
		while (int_stack[id] > 3)
		{
			int_stack[id] = 0;
			id++;
			int_stack[id]++;
		}
		id = 0;
		if (count_pa(int_stack) == 3)
		{
			a = NULL;
			b = NULL;
			ft_stackadd_back(&b, ft_stacknew(1));
			ft_stackadd_back(&b, ft_stacknew(2));
			ft_stackadd_back(&b, ft_stacknew(3));
			print_moves(int_stack, poss, &a, &b);
			ft_stackclear(&a);
			j++;
		}
	}
	printf("%d\n", j);
	return (0);
}