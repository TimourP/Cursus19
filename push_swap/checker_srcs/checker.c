/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:49:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/04 15:25:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_entry(t_list **entry, t_stack **a)
{
	int		bytes;
	char	*buff;
	t_list	*new;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = get_next_line(0, &buff);
		if (bytes >= 0)
		{
			new = ft_lstnew(ft_strdup(buff));
			if (!new)
			{
				ft_lstclear(entry, free);
				ft_stackclear(a);
				print_errors(MALLOC_ERROR);
				exit(EXIT_FAILURE);
			}
			ft_lstadd_back(entry, new);
		}
		free(buff);
	}
}

static void	execute_move(t_stack **a, t_stack **b, int move)
{
	if (move == 0)
		swap(a, NULL);
	else if (move == 1)
		swap(b, NULL);
	else if (move == 2)
		swap_swap(a, b, NULL);
	else if (move == 3)
		push_a(a, b, NULL);
	else if (move == 4)
		push_b(a, b, NULL);
	else if (move == 5)
		rotate(a, NULL);
	else if (move == 6)
		rotate(b, NULL);
	else if (move == 7)
		rotate_rotate(a, b, NULL);
	else if (move == 8)
		r_reverse(a, NULL);
	else if (move == 9)
		r_reverse(b, NULL);
	else if (move == 10)
		r_r_reverse(a, b, NULL);
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
	const char	*move[11] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;
	t_stack		*b;

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
		if (i == 11)
		{
			ft_stackclear(&a);
			ft_lstclear(&entry, free);
			exit_message(ARGS_TYPE_ERROR, &a);
		}
		entry = entry->next;
	}
	check_sort(a, b);
	ft_stackclear(&a);
	ft_stackclear(&b);
	ft_lstclear(&entry, free);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
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
		get_entry(&entry, &a);
		resolve_checker(a, entry);
	}
	return (0);
}
