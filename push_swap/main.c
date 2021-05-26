/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:08:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/26 16:35:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int	is_in_int(int *list, int elem, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (list[i] == elem)
			return (1);
	return (0);
}

static int	free_return(int *lst)
{
	free(lst);
	lst = NULL;
	return (0);
}

int	main(void)
{
	int			ra;
	const int	min_max[2] = {0, 10000};
	const int	total = 100;
	int			*list;
	int			i;

	list = malloc(sizeof(int) * total);
	i = -1;
	srand(time(NULL));
	while (i < total)
	{
		ra = rand() % ((min_max[1] + 1) - min_max[0]) + min_max[0];
		if (!is_in_int(list, ra, total) && ++i + 1)
			list[i] = ra;
	}
	i = -1;
	printf("make push_swap && make checker && ./push_swap ");
	while (++i < total)
		printf("%d ", list[i]);
	/*i = -1;
	printf(" | ./checker ");
	while (++i < total)
		printf("%d ", list[i]);*/
	printf(" && rm a.out\n");
	return (free_return(list));
}
