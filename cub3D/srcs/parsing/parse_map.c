/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:24:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/25 10:00:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list	*list_from_file(char *map_path)
{
	int fd;
	int ret;
	char *line;
	t_list *map_lst = NULL;
	t_list *new;

	fd = open(map_path, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!(new = ft_lstnew(line)))
			return (NULL);
		ft_lstadd_back(&map_lst, new);
	}
	if (ret == -1 || !(new = ft_lstnew(line)))
			return (NULL);
	ft_lstadd_back(&map_lst, new);
	return (map_lst);
}

int	fill_map_struct(t_map *c_map, t_list *map_list)
{
	c_map->test = 0;
	printf("%s\n", map_list->content);
	return (0);
}

int	parse_map(t_map *c_map, char *map_path)
{
	t_list *map_list;

	if (!(map_list = list_from_file(map_path)))
		return (0);
	ft_lstprint(map_list);
	ft_lstclear(&map_list, free);
	c_map->test = 0;
	return (1);
}
