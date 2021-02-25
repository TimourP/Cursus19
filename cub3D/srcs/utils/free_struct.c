/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:13:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/25 16:26:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_t_map(t_map *c_map)
{
	free(c_map->south_t);
	free(c_map->north_t);
	free(c_map->west_t);
	free(c_map->east_t);
	free(c_map->sprite_t);
	free(c_map->floor_t);
	free(c_map->ceiling_t);
	free_all(c_map->map, c_map->map_h);
}