/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:08:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/12 18:42:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int main(int argc, char **argv)
{
	int i;
	t_stack *a;
	t_stack *b;
	t_stack *new;

	i = 0;
	a = NULL;
	b = NULL;
	while (++i < argc)
	{
		new = ft_stacknew(ft_atoi(argv[i]));
		ft_stackadd_back(&a, new);
	}
	r_r_reverse(&a, &b);
	print_stack(a, b);
	return (0);
}
