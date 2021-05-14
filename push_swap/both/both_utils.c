/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:38:21 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/14 13:40:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_struct(int argc, char **argv, t_stack **stack)
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

void	get_entry(t_list **entry)
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
