/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:41:23 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/27 10:41:31 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_map_struct(t_map *c_map)
{
	c_map->map_w = 0;
	c_map->map_h = 0;
	c_map->screen_w = 0;
	c_map->screen_h = 0;
	c_map->north_t = malloc(sizeof(t_image));
	c_map->north_t->path = NULL;
	c_map->south_t = malloc(sizeof(t_image));
	c_map->south_t->path = NULL;
	c_map->east_t = malloc(sizeof(t_image));
	c_map->east_t->path = NULL;
	c_map->west_t = malloc(sizeof(t_image));
	c_map->west_t->path = NULL;
	c_map->sprite_t = malloc(sizeof(t_image));
	c_map->sprite_t->path = NULL;
	c_map->heart_t = malloc(sizeof(t_image));
	c_map->heart_t->path = NULL;
	c_map->hunger_t = malloc(sizeof(t_image));
	c_map->hunger_t->path = NULL;
	c_map->empty_heart_t = malloc(sizeof(t_image));
	c_map->empty_heart_t->path = NULL;
	c_map->empty_hunger_t = malloc(sizeof(t_image));
	c_map->empty_hunger_t->path = NULL;
	c_map->floor_t = 0;
	c_map->ceiling_t = 0;
}
