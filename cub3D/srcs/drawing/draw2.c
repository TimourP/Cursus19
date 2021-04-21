/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:11:45 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/21 15:53:27 by tpetit           ###   ########.fr       */
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
		+ (c_ray->look_offset);
	const int	texture_x = texture->width * y_value;

	i = -1;
	if (!BONUS)
	{
		while (++i < offset && i < c_ray->screen_h)
			draw_pixel(c_ray, x_len[0], i, c_ray->c_map->floor_t);
	}
	i = -1;
	if (offset < 0)
		i = -offset;
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
	int color;
	int to_remove;
	float ratio;

	while (c_list)
	{
		ratio = (float)c_list->content->height / c_ray->c_map->sprite_t->height;
		i = c_list->content->start_y - 1;
		while (++i < c_list->content->end_y)
		{
			j = c_list->content->start_x - 1;
			while (++j < c_list->content->end_x)
			{
				get_pixel(c_ray->c_map->sprite_t, (j - c_list->content->start_x + c_list->content->offset_x) / ratio, (i - c_list->content->start_y + c_list->content->offset_y) / ratio, &color);
				if (color != 1193046 && c_list->content->distance < c_ray->all_distances[j])
					draw_pixel(c_ray, j, i, color);
			}
		}
		c_list = c_list->next;
	}
}
