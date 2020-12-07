/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:03:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/03 10:05:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	int i;
	int j;
	char *li;
	int value;

	i = open("./test.txt", O_RDONLY);
	j = open("./testbis.txt", O_RDONLY);

	for (int u = 0; u < 100 ; u++)
	{
		value = get_next_line(u % 2 ? i : j, &li);
		printf("%d %d : %s\n", u, value, li);
	}
	close(i);
	close(j);
	return 0;
}