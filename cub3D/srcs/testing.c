/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:36:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/25 13:09:42 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map_struct(t_map *c_map)
{
	printf("screen width : %d\n", c_map->screen_w);
	printf("screen height : %d\n", c_map->screen_h);
	printf("map width : %d\n", c_map->map_w);
	printf("map height : %d\n", c_map->map_h);
	printf("south texture : %s\n", c_map->south_t);
	printf("north texture : %s\n", c_map->north_t);
	printf("west texture : %s\n", c_map->west_t);
	printf("east texture : %s\n", c_map->east_t);
	printf("floor texture : %s\n", c_map->floor_t);
	printf("ceiling texture : %s\n", c_map->ceiling_t);
}