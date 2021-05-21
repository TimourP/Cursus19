/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:38:21 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/21 10:17:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_struct(int argc, char **argv, t_stack **stack)
{
	int		i;
	t_stack	*new;

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
