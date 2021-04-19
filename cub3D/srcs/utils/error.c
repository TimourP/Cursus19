/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:23:50 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/19 11:58:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	free_on_error(t_map *c_map, int error_type)
{
	if (error_type == MAP_ERROR)
		printf("There is an error in the map\n");
	if (error_type == MALLOC_ERROR)
		printf("Malloc error\n");
	if (error_type == PARSING_ERROR)
		printf("There is an error in the map file\n");
	if (error_type == FILE_ERROR)
		printf("Error while trying to read image file\n");
	free_t_map(c_map);
	return (0);
}

int	check_parsing_error(t_map *c_map)
{
	print_map_struct(c_map);
	if (!map_error(c_map))
		return (free_on_error(c_map, MAP_ERROR));
	if (c_map->screen_h == 0 || c_map->screen_w == 0
		|| c_map->map_w == 0 || c_map->map_h == 0)
		return (free_on_error(c_map, PARSING_ERROR));
	if (!c_map->south_t->path || !c_map->north_t->path
		|| !c_map->east_t->path || !c_map->west_t->path)
		return (free_on_error(c_map, PARSING_ERROR));
	return (1);
}
