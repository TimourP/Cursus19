/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:24:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/24 19:50:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_map(t_map *c_map, char *map_path)
{
	int fd;
	int ret;
	char *line;

	fd = open(map_path, O_RDONLY);
	printf("%s %d\n", map_path, fd);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	if (ret == -1)
		return (-1);
	c_map->test = 0;
	return (1);
}