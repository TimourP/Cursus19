/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:31:48 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/28 20:53:05 by tpetit           ###   ########.fr       */
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

int	get_monsters(t_ray *c_ray, t_monster_list *lst)
{
	t_sprite	*new_sprite;

	while (lst)
	{
		float x_prim;
		float y_prim;
		float angle = c_ray->player_angle + PI * 1.5;
		float sprite_angle;
		const float total_angle = (PI / FOV) / PI * 180;
		if (angle < 0)
			angle += 2 * PI;
		if (angle > 2 * PI)
			angle -= 2 * PI;
		x_prim = cos(angle) * (lst->content->x - c_ray->player_posx) + sin(angle) * (lst->content->y - c_ray->player_posy);
		y_prim = - sin(angle) * (lst->content->x - c_ray->player_posx) + cos(angle) * (lst->content->y - c_ray->player_posy);
		sprite_angle = PI * 0.5 - atan(y_prim / x_prim);
		sprite_angle = x_prim > 0 ? sprite_angle / PI * 180 : - (PI - sprite_angle) / PI * 180;
		new_sprite = malloc(sizeof(t_sprite));
		new_sprite->offset_x = 0;
		new_sprite->offset_y = 0;
		new_sprite->distance = sqrt(pow(x_prim, 2) + pow(y_prim, 2));
		new_sprite->height = c_ray->screen_h / new_sprite->distance * 1.3;
		new_sprite->img = lst->content->img;
		if (y_prim < 0)
			new_sprite->height = 0;
		new_sprite->start_x = (c_ray->screen_w - new_sprite->height) / 2 - sprite_angle / total_angle * c_ray->screen_w;
		new_sprite->end_x = new_sprite->start_x + new_sprite->height;
		new_sprite->start_y = (c_ray->screen_h - new_sprite->height) / 2 + c_ray->look_offset - c_ray->tic + 50;
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
		lst = lst->next;
	}
	return (1);
}

int	get_all_sprites(t_ray *c_ray)
{
	int			i;
	int			j;
	t_sprite	*new_sprite;

	i = -1;
	while (++i < c_ray->c_map->map_h)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w)
		{
			if (is_in_str("234abc", c_ray->c_map->map[i][j]))
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
				new_sprite = malloc(sizeof(t_sprite));
				new_sprite->offset_x = 0;
				new_sprite->offset_y = 0;
				new_sprite->distance = sqrt(pow(x_prim, 2) + pow(y_prim, 2));
				new_sprite->height = c_ray->screen_h / new_sprite->distance * 1.3;
				new_sprite->img = get_sprite_image(c_ray, c_ray->c_map->map[i][j]);
				if (y_prim < 0)
					new_sprite->height = 0;
				new_sprite->start_x = (c_ray->screen_w - new_sprite->height) / 2 - sprite_angle / total_angle * c_ray->screen_w;
				new_sprite->end_x = new_sprite->start_x + new_sprite->height;
				new_sprite->start_y = (c_ray->screen_h - new_sprite->height) / 2 + c_ray->look_offset;
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
	get_monsters(c_ray, c_ray->monster_list);
	ft_sprsort(c_ray->start_list);
	return (1);
}
