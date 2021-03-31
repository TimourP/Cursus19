/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:11:45 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/31 18:08:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_line(t_ray *c_ray, int x_y_l[3], float angle, const int color)
{
	float	dx;
	float	dy;
	int		i;
	int		x;
	int		y;

	i = -1;
	dx = cos(-angle);
	dy = sin(-angle);
	while (++i < x_y_l[2])
	{
		x = x_y_l[0] + (i * dx);
		y = x_y_l[1] - (i * dy);
		if (x > 0 && y > 0 && x < MINI_WIDTH && y < MINI_HEIGHT)
			draw_pixel(c_ray, x, y, color);
	}
}

void	draw_vertical_line(t_ray *c_ray, const int x,
	int length, const int color)
{
	int			i;
	const int	offset = (c_ray->screen_h - length) / 2 + c_ray->look_offset;

	i = -1;
	if (!BONUS)
	{
		while (++i < offset && i < c_ray->screen_h)
			draw_pixel(c_ray, x, i, c_ray->c_map->floor_t);
	}
	i = -1;
	while (++i < length && i + offset < c_ray->screen_h)
	{
		if (i + offset >= 0)
			draw_pixel(c_ray, x, i + offset, color);
	}
	i--;
	while (++i + offset < c_ray->screen_h)
	{
		if (i + offset >= 0)
			draw_pixel(c_ray, x, i + offset, c_ray->c_map->ceiling_t);
	}
}

void	draw_vertical_texture(t_ray *c_ray, int x_len[2],
	t_image *texture, float y_value)
{
	int			i;
	const float	texture_ratio = (float)x_len[1] / texture->height;
	int			color;
	const int	offset = (c_ray->screen_h - x_len[1]) / 2
		+ (BONUS * c_ray->look_offset);
	const int	texture_x = texture->width * y_value;

	i = -1;
	if (!BONUS)
	{
		while (++i < offset && i < c_ray->screen_h)
			draw_pixel(c_ray, x_len[0], i, c_ray->c_map->floor_t);
	}
	i = -1;
	while (++i < x_len[1] && i + offset < c_ray->screen_h)
	{
		get_pixel(texture, texture_x, i / texture_ratio, &color);
		if (i + offset >= 0)
			draw_pixel(c_ray, x_len[0], i + offset, color);
	}
	i--;
	while (++i + offset < c_ray->screen_h)
		if (i + offset >= 0)
			draw_pixel(c_ray, x_len[0], i + offset, c_ray->c_map->ceiling_t);
}

void	draw_sprite(t_ray *c_ray, t_sprite_list *c_list)
{
	int i;
	int j;
	int	sprite_height;
	int color = 0;
	float rapport;
	int	endmstart;

	while (c_list)
	{
		endmstart = c_list->content->end_x - c_list->content->start_x;
		sprite_height = c_ray->screen_h / c_list->content->distance * 1.2;
		rapport = (float)c_ray->c_map->sprite_t->height / sprite_height;
		i = -1;
		//ft_sprprint(c_ray->start_list);
		while (++i < sprite_height)
		{
			j = -1;
			while (++j < sprite_height)
			{
				get_pixel(c_ray->c_map->sprite_t, i * rapport, j * rapport, &color);
				if (j + (c_ray->screen_h - sprite_height) / 2 > 0 && j + (c_ray->screen_h - sprite_height) / 2 < c_ray->screen_h && color != 1193046 && (i + c_list->content->start_x + (endmstart - sprite_height) / 2) < c_ray->screen_w)
					draw_pixel(c_ray, i + c_list->content->start_x + (endmstart - sprite_height) / 2, j + (c_ray->screen_h - sprite_height) / 2, color);
			}
		}
		c_list = c_list->next;
	}
}