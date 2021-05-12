/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:49:51 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/12 12:00:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_image	*get_sprite_image(t_ray *c_ray, char c)
{
	if (c == '2')
		return (c_ray->c_map->sprite_t);
	if (c == '3')
		return (c_ray->bonus_images->other_sprite_0);
	if (c == '4')
		return (c_ray->bonus_images->other_sprite_1);
	if (c == 'a')
		return (c_ray->bonus_images->good_food);
	if (c == 'b')
		return (c_ray->bonus_images->good_health);
	if (c == 'c')
		return (c_ray->bonus_images->bad_health);
	return (c_ray->bonus_images->heart_t);
}

void	init_new_sprite(t_ray *c_ray, t_sprite *new_sprite,
	float x_prim, float y_prim)
{
	if (!new_sprite)
		exit_message(MALLOC_ERROR);
	new_sprite->offset_x = 0;
	new_sprite->offset_y = 0;
	new_sprite->distance = sqrt(pow(x_prim, 2) + pow(y_prim, 2));
	new_sprite->height = c_ray->screen_h / new_sprite->distance * 1.3;
	new_sprite->shot_count = 0;
	if (y_prim < 0)
		new_sprite->height = 0;
}

t_sprite	*init_monster(t_ray *c_ray, t_monster_list *lst,
		float x_prim, float y_prim)
{
	t_sprite	*new_sprite;

	new_sprite = malloc(sizeof(t_sprite));
	if (!new_sprite)
		exit_message(MALLOC_ERROR);
	new_sprite->offset_x = 0;
	new_sprite->offset_y = 0;
	new_sprite->id = lst->content->id;
	new_sprite->shot_count = lst->content->shot_count;
	new_sprite->distance = sqrt(pow(x_prim, 2) + pow(y_prim, 2));
	new_sprite->height = c_ray->screen_h / new_sprite->distance * 1.3;
	new_sprite->img = lst->content->img;
	if (y_prim < 0)
		new_sprite->height = 0;
	return (new_sprite);
}

float	set_monster_angle(t_ray *c_ray)
{
	float	angle;

	angle = c_ray->player_angle + PI * 1.5;
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}
