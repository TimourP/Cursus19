/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:38:21 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/04 11:07:48 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	is_yet(t_stack **stack, int new)
{
	t_stack	*tmp;

	if (stack)
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->content == new)
			{
				ft_stackclear(stack);
				print_errors(DUPLICATES_ARGS);
				exit(EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
	}
}

void	fill_struct(int argc, char **argv, t_stack **stack)
{
	int		i;
	int		value;
	t_stack	*new;

	i = 0;
	while (++i < argc)
	{
		value = ft_atoi(argv[i]);
		is_yet(stack, value);
		new = ft_stacknew(value);
		if (!new)
		{
			ft_stackclear(stack);
			print_errors(MALLOC_ERROR);
			exit(EXIT_FAILURE);
		}
		ft_stackadd_back(stack, new);
	}
}
