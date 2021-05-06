/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:31:48 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 20:22:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	get_sprites_loop_end(t_ray *c_ray, float sprite_angle,
		float total_angle, t_sprite *new_sprite)
{
	new_sprite->start_x = (c_ray->screen_w - new_sprite->height) / 2
		- sprite_angle / total_angle * c_ray->screen_w;
	new_sprite->end_x = new_sprite->start_x + new_sprite->height;
	new_sprite->start_y = (c_ray->screen_h - new_sprite->height) / 2
		+ c_ray->look_offset;
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
}

static void	get_sprites_loop(t_ray *c_ray, int i, int j, t_sprite *new_sprite)
{
	float		x_prim;
	float		y_prim;
	float		angle;
	float		sprite_angle;
	const float	total_angle = (PI / FOV) / PI * 180;

	angle = c_ray->player_angle + PI * 1.5;
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	x_prim = cos(angle) * (j + 0.5 - c_ray->player_posx)
		+ sin(angle) * (i + 0.5 - c_ray->player_posy);
	y_prim = -sin(angle) * (j + 0.5 - c_ray->player_posx)
		+ cos(angle) * (i + 0.5 - c_ray->player_posy);
	sprite_angle = PI * 0.5 - atan(y_prim / x_prim);
	if (x_prim > 0)
		sprite_angle = sprite_angle / PI * 180;
	else
		sprite_angle = - (PI - sprite_angle) / PI * 180;
	new_sprite = malloc(sizeof(t_sprite));
	init_new_sprite(c_ray, new_sprite, x_prim, y_prim);
	new_sprite->img = get_sprite_image(c_ray, c_ray->c_map->map[i][j]);
	get_sprites_loop_end(c_ray, sprite_angle, total_angle, new_sprite);
	ft_spradd_back(&c_ray->start_list, ft_sprnew(new_sprite));
}

void	get_monsters_end(t_ray *c_ray, t_sprite *new_sprite,
	float sprite_angle)
{
	const float	total_angle = (PI / FOV) / PI * 180;

	new_sprite->start_x = (c_ray->screen_w - new_sprite->height) / 2
		- sprite_angle / total_angle * c_ray->screen_w;
	new_sprite->end_x = new_sprite->start_x + new_sprite->height;
	new_sprite->start_y = (c_ray->screen_h - new_sprite->height) / 2
		+ (float)(c_ray->look_offset - c_ray->tic + 50) / 50
		* new_sprite->height / 8 + c_ray->look_offset;
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

int	get_monsters(t_ray *c_ray, t_monster_list *lst)
{
	t_sprite	*new_sprite;
	float		x_prim;
	float		y_prim;
	float		angle;
	float		sprite_angle;

	while (lst)
	{
		angle = set_monster_angle(c_ray);
		x_prim = cos(angle) * (lst->content->x - c_ray->player_posx)
			+ sin(angle) * (lst->content->y - c_ray->player_posy);
		y_prim = -sin(angle) * (lst->content->x - c_ray->player_posx)
			+ cos(angle) * (lst->content->y - c_ray->player_posy);
		sprite_angle = PI * 0.5 - atan(y_prim / x_prim);
		if (x_prim > 0)
			sprite_angle = sprite_angle / PI * 180;
		else
			sprite_angle = -(PI - sprite_angle) / PI * 180;
		new_sprite = init_monster(c_ray, lst, x_prim, y_prim);
		get_monsters_end(c_ray, new_sprite, sprite_angle);
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
	new_sprite = NULL;
	while (++i < c_ray->c_map->map_h)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w)
		{
			if (is_in_str("234abc", c_ray->c_map->map[i][j]))
				get_sprites_loop(c_ray, i, j, new_sprite);
		}
	}
	get_monsters(c_ray, c_ray->monster_list);
	ft_sprsort(c_ray->start_list);
	return (1);
}
