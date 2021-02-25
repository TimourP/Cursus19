/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:24:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/25 16:25:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list	*list_from_file(char *map_path)
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*map_lst;
	t_list	*new;

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

int		get_bigger_line(t_list *map_list, int *lines_count)
{
	int max;

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

int		parse_map_to_str(t_map *c_map, t_list *map_list)
{
	int			i;
	int			j;

	c_map->map_w = get_bigger_line(map_list, &(c_map->map_h));
	if (!c_map->map_h || !(c_map->map = malloc(sizeof(char**) * c_map->map_h)))
		return (0);
	i = -1;
	while (++i < c_map->map_h)
	{
		if (!(c_map->map[i] = malloc(sizeof(char) * (c_map->map_w + 1))))
			return (0);
	}
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

int		fill_map_struct(t_map *c_map, t_list *map_list)
{
	int error;

	error = 1;
	while (map_list && map_list->next)
	{
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
		else if (ft_strncmp(map_list->content, "C", 1) == 0)
			error = get_colors(c_map, map_list->content, 'c');
		else if (ft_strncmp(map_list->content, "F", 1) == 0)
			error = get_colors(c_map, map_list->content, 'f');
		else if (ft_strncmp(map_list->content, "S", 1) == 0)
			error = get_textures(c_map, map_list->content, 'S');
		else if (ft_strlen(map_list->content) == 0)
			;
		else
			break ;
		if (error == 0)
			return (0);
		map_list = map_list->next;
	}
	return (parse_map_to_str(c_map, map_list));
}

int		parse_map(t_map *c_map, char *map_path)
{
	t_list *map_list;

	init_map_struct(c_map);
	if (!(map_list = list_from_file(map_path)))
		return (0);
	if (!(fill_map_struct(c_map, map_list)))
		return (0);
	ft_lstclear(&map_list, free);
	return (1);
}
