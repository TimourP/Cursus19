/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:45:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/22 17:22:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *line;
	int fd;
	int ret;
	int i;

	i = -1;
	fd = open("test.txt", O_RDONLY);
	while (++i < 10)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		printf("str (%d) : |%s|\n", ret, line);
		free(line);
	}
	
	return (0);
}