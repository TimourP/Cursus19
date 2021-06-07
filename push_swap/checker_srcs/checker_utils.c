/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:33:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 13:34:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_entry(t_list **entry, t_stack **a, char *line)
{
	const char	*move[11] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	int			i;
	int			value;

	i = -1;
	value = 0;
	while (++i < 11)
		if (ft_strncmp(line, move[i]) == 0 || !line[0])
			value = 1;
	if (!value)
	{
		ft_lstclear(entry, free);
		free(line);
		exit_message(INVALID_MOVE, a);
	}
}
