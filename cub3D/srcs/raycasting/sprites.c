/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:39:02 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/21 15:30:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_look(t_ray *c_ray)
{
	printf("%f\n", c_ray->player_angle);
	if (c_ray->player_angle >= PI * 1.25 && c_ray->player_angle < 1.75 * PI)
		return (0);
	if (c_ray->player_angle >= 0.25 * PI && c_ray->player_angle < 0.75 * PI)
		return (2);
	if (c_ray->player_angle >= 0.75 && c_ray->player_angle < 1.25 * PI)
		return (3);
	return (1);
}

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
				float x_prim;
				float y_prim;
				float angle = c_ray->player_angle + PI * 1.5;
				float sprite_angle;
				float x_add = (float)(c_ray->tic - 50) / 400 + 0.5;
				const float total_angle = (PI / FOV) / PI * 180;
				x_add = 0.5;
				if (angle < 0)
					angle += 2 * PI;
				if (angle > 2 * PI)
					angle -= 2 * PI;
				x_prim = cos(angle) * (j + x_add - c_ray->player_posx) + sin(angle) * (i + x_add - c_ray->player_posy);
				y_prim = - sin(angle) * (j + x_add - c_ray->player_posx) + cos(angle) * (i + x_add - c_ray->player_posy);
				sprite_angle = PI * 0.5 - atan(y_prim / x_prim);
				sprite_angle = x_prim > 0 ? sprite_angle / PI * 180 : - (PI - sprite_angle) / PI * 180;
				//printf("%f %f %f %f\n", sprite_angle, total_angle, sprite_angle / total_angle * 2, 0.0);
				new_sprite = malloc(sizeof(t_sprite));
				new_sprite->offset_x = 0;
				new_sprite->offset_y = 0;
				new_sprite->distance = sqrt(pow(x_prim, 2) + pow(y_prim, 2));
				new_sprite->height = c_ray->screen_h / new_sprite->distance;
				if (y_prim < 0)
					new_sprite->height = 0;
				new_sprite->start_x = (c_ray->screen_w - new_sprite->height) / 2 - sprite_angle / total_angle * c_ray->screen_w;
				new_sprite->end_x = new_sprite->start_x + new_sprite->height;
				new_sprite->start_y = (c_ray->screen_h - new_sprite->height) / 2 + (c_ray->look_offset * BONUS);
				new_sprite->end_y = new_sprite->start_y + new_sprite->height;
				if (new_sprite->end_x >= c_ray->screen_w)
					new_sprite->end_x = c_ray->screen_w - 1;
				if (new_sprite->start_x < 0)
				{
					new_sprite->offset_x = 0 - new_sprite->start_x;
					new_sprite->start_x = 0;
				}
				if (new_sprite->end_y >= c_ray->screen_h)
					new_sprite->end_y = c_ray->screen_h - 1;
				if (new_sprite->start_y < 0)
				{
					new_sprite->offset_y = 0 - new_sprite->start_y;
					new_sprite->start_y = 0;
				}
				ft_spradd_back(&c_ray->start_list, ft_sprnew(new_sprite));
			}
		}
	}
	ft_sprsort(c_ray->start_list);
	return (1);
}
