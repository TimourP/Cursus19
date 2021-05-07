/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:43:42 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/07 14:01:02 by tpetit           ###   ########.fr       */
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
	if (c_map->north_t)
		c_map->north_t->path = NULL;
	c_map->south_t = malloc(sizeof(t_image));
	if (c_map->south_t)
		c_map->south_t->path = NULL;
	c_map->east_t = malloc(sizeof(t_image));
	if (c_map->east_t)
		c_map->east_t->path = NULL;
	c_map->west_t = malloc(sizeof(t_image));
	if (c_map->west_t)
		c_map->west_t->path = NULL;
	c_map->sprite_t = malloc(sizeof(t_image));
	if (c_map->sprite_t)
		c_map->sprite_t->path = NULL;
	c_map->floor_t = 0;
	c_map->ceiling_t = 0;
	if (!c_map->north_t || !c_map->south_t || !c_map->east_t
		|| !c_map->west_t || !c_map->sprite_t)
		exit_message(MALLOC_ERROR);
}
