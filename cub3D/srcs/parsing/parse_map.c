/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:24:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 16:28:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_bigger_line(t_list *map_list, int *lines_count)
{
	int	max;

	max = 0;
	*lines_count = 0;
	while (map_list && map_list->next && ft_strlen(map_list->content) > 0)
	{
		if ((int)ft_strlen(map_list->content) > max)
			max = (int)ft_strlen(map_list->content);
		map_list = map_list->next;
		*lines_count += 1;
	}
	if (map_list && (int)ft_strlen(map_list->content) > max)
		max = (int)ft_strlen(map_list->content);
	if (map_list)
		*lines_count += 1;
	return (max);
}

int	parse_map_to_str(t_map *c_map, t_list *map_list)
{
	int	i;
	int	j;

	c_map->map_w = get_bigger_line(map_list, &(c_map->map_h));
	if (!c_map->map_h || !big_m(&c_map->map, sizeof(char **) * c_map->map_h))
		return (0);
	i = -1;
	while (++i < c_map->map_h)
		if (!ft_malloc(&c_map->map[i], sizeof(char) * (c_map->map_w + 1)))
			return (0);
	i = -1;
	while (++i < c_map->map_h)
	{
		j = -1;
		while (++j < c_map->map_w)
		{
			if ((int)ft_strlen(map_list->content) > j)
				c_map->map[i][j] = map_list->content[j];
			else
				c_map->map[i][j] = ' ';
		}
		c_map->map[i][j] = 0;
		map_list = map_list->next;
	}
	return (1);
}

static int	fill_map_struct2(t_map *c_map, t_list *map_list)
{
	int	error;

	error = 1;
	if (ft_strncmp(map_list->content, "R", 1) == 0)
		get_screen_resolution(c_map, map_list->content);
	else if (ft_strncmp(map_list->content, "NO", 2) == 0)
		error = get_textures(c_map, map_list->content, 'n');
	else if (ft_strncmp(map_list->content, "SO", 2) == 0)
		error = get_textures(c_map, map_list->content, 's');
	else if (ft_strncmp(map_list->content, "EA", 2) == 0)
		error = get_textures(c_map, map_list->content, 'e');
	else if (ft_strncmp(map_list->content, "WE", 2) == 0)
		error = get_textures(c_map, map_list->content, 'w');
	else if (ft_strncmp(map_list->content, "C ", 2) == 0)
		error = get_colors(c_map, map_list->content, 'c');
	else if (ft_strncmp(map_list->content, "F ", 2) == 0)
		error = get_colors(c_map, map_list->content, 'f');
	else if (ft_strncmp(map_list->content, "S ", 2) == 0)
		error = get_textures(c_map, map_list->content, 'S');
	else if (ft_strlen(map_list->content) != 0)
		return (2);
	if (error == 0)
		return (0);
	return (error);
}

int	fill_map_struct(t_map *c_map, t_list *map_list)
{
	int	error;

	error = 1;
	while (map_list && map_list->next)
	{
		error = fill_map_struct2(c_map, map_list);
		if (error == 2)
			break ;
		else if (error == 0)
			return (0);
		map_list = map_list->next;
	}
	return (parse_map_to_str(c_map, map_list));
}

int	parse_map(t_map *c_map, char *map_path)
{
	t_list	*map_list;

	init_map_struct(c_map);
	map_list = list_from_file(map_path);
	if (!map_list)
		return (0);
	if (!(fill_map_struct(c_map, map_list)))
		return (0);
	ft_lstclear(&map_list, free);
	return (1);
}
