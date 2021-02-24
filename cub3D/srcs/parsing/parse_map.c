/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:24:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/24 20:17:15 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_map(t_map *c_map, char *map_path)
{
	int fd;
	int ret;
	char *line;
	t_list *map_lst;
	t_list *new;

	fd = open(map_path, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!(new = ft_lstnew(line)))
			return (-1);
		ft_lstadd_back(&map_lst, new);
		free(line);
	}
	if (ret == -1 || !(new = ft_lstnew(line)))
			return (-1);
	ft_lstadd_back(&map_lst, new);
	free(line);
	return (1);
}