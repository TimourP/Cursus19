/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:03:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 12:24:21 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int i;
	int j;
	char *li;
	int value;

	i = open("./test.txt", O_RDONLY);
	j = open("./testbis.txt", O_RDONLY);
	li = 0;

	for (int u = 0; u < 50 ; u++)
	{
		value = get_next_line(j, &li);
		printf("%d %d : %s\n", u, value, li);
	}
	close(i);
	close(j);
	return 0;
}