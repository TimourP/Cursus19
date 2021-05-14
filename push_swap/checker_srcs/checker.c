/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:49:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/14 13:13:39 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int  check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-'))
				return (0);
		}
	}
	return (1);
}

static void	fill_struct(int argc, char **argv, t_stack **stack)
{
	int i;
	t_stack *new;

	i = 0;
	while (++i < argc)
	{
		new = ft_stacknew(ft_atoi(argv[i]));
		if (!new)
		{
			ft_stackclear(stack);
			print_errors(MALLOC_ERROR);
			exit(EXIT_FAILURE);
		}
		ft_stackadd_back(stack, new);
	}
}

static void	get_entry(t_list **entry)
{
	int	bytes;
	char	buff[64];
	t_list	*new;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(0, buff, 64);
		if (bytes >= 0)
		{
			new = ft_lstnew(ft_strdup(buff));
			if (!new)
			{
				ft_lstclear(entry, free);
				print_errors(MALLOC_ERROR);
				exit(EXIT_FAILURE);
			}
			ft_lstadd_back(entry, new);
		}
	}
}

static void	execute_move(t_stack **a, t_stack **b, int move)
{
	if (move == 0)
		swap(a);
	else if (move == 1)
		swap(b);
	else if (move == 2)
		swap_swap(a, b);
	else if (move == 3)
		push_a(a, b);
	else if (move == 4)
		push_b(a, b);
	else if (move == 5)
		rotate(a);
	else if (move == 6)
		rotate(b);
	else if (move == 7)
		rotate_rotate(a, b);
	else if (move == 8)
		r_reverse(a);
	else if (move == 9)
		r_reverse(b);
	else if (move == 10)
		r_r_reverse(a, b);
}

static void	check_sort(t_stack *a, t_stack *b)
{
	if (!b && a)
	{
		while (a->next)
		{
			if (a->content > a->next->content)
			{
				ft_putstr("KO\n");
				return ;
			}
			a = a->next;
		}
		ft_putstr("OK\n");
	}
	else
		ft_putstr("KO\n");
}

static void	resolve_checker(t_stack *a, t_list *entry)
{
	const char	*move[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	int i;
	t_stack *b;

	b = NULL;
	if (!entry)
		return ;
	while (entry->next)
	{
		i = -1;
		while (++i < 11)
		{
			if (ft_strncmp(entry->content, move[i]) == 0)
			{
				execute_move(&a, &b, i);
				break ;
			}
		}
		entry = entry->next;
	}
	print_stack(a, b);
	check_sort(a, b);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_list	*entry;

	a = NULL;
	entry = NULL;
	if (argc <= 1)
		print_errors(ARGS_NUMBER);
	else if (!check_args(argc, argv))
		print_errors(ARGS_TYPE_ERROR);
	else
	{
		fill_struct(argc, argv, &a);
		get_entry(&entry);
		resolve_checker(a, entry);
	}
	return (0);
}