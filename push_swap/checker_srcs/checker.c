/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:49:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/14 12:42:56 by tpetit           ###   ########.fr       */
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
	}
	return (0);
}