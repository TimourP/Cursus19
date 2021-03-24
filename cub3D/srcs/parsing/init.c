/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:43:42 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/24 10:05:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map_struct(t_map *c_map)
{
	c_map->map_w = 0;
	c_map->map_h = 0;
	c_map->screen_w = 0;
	c_map->screen_h = 0;
	c_map->north_t = malloc(sizeof(t_image));
	c_map->south_t = malloc(sizeof(t_image));
	c_map->east_t = malloc(sizeof(t_image));
	c_map->west_t = malloc(sizeof(t_image));
	c_map->floor_t = 0;
	c_map->ceiling_t = 0;
}
