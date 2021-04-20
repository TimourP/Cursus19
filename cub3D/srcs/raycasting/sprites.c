/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:39:02 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/20 13:00:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_all_sprites(t_ray *c_ray)
{
	int			i;
	int			j;
	t_sprite	*new_sprite;
	float		x_diff;

	i = -1;
	while (++i < c_ray->c_map->map_h)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w)
		{
			if (c_ray->c_map->map[i][j] == '2')
			{
				x_diff = (j + 0.5) - c_ray->player_posx;
				new_sprite = malloc(sizeof(t_sprite));
				new_sprite->distance = sqrt(pow((j + 0.5
						- c_ray->player_posx), 2) + pow((i + 0.5
						- c_ray->player_posy), 2));
				new_sprite->distance = sqrt(pow(new_sprite->distance, 2) - pow(j + 0.5 - c_ray->player_posx, 2));
				new_sprite->distance = new_sprite->distance;
				new_sprite->height = c_ray->screen_h / new_sprite->distance;
				new_sprite->start_x = c_ray->screen_w / 2 - new_sprite->height * 1.3 / 2 + x_diff * new_sprite->height * 1.3;
				float angle = c_ray->player_angle + PI / 2;
				new_sprite->start_x = new_sprite->start_x - tan(angle) * new_sprite->distance * new_sprite->height * 1.3;
				new_sprite->end_x = new_sprite->start_x + new_sprite->height;
				ft_spradd_back(&c_ray->start_list, ft_sprnew(new_sprite));
			}
		}
	}
	return (1);
}
