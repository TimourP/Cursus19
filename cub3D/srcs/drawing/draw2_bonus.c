/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:39:26 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/28 15:59:48 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

static int	shadow(int color, double props)
{
	if (props < 0)
		props = 0;
	else if (props > 1)
		props = 1;
	return (((int)(((color & 0x00FF0000) >> 16) * props) << 16)
			| ((int)(((color & 0x0000FF00) >> 8) * props) << 8)
			| ((int)((color & 0x000000FF) * props)));
}

void	draw_vertical_line(t_ray *c_ray, const int x,
	int length, const int color)
{
	int			i;
	const int	offset = (c_ray->screen_h - length) / 2 + c_ray->look_offset;

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
			draw_pixel(c_ray, x, i + offset, c_ray->c_map->floor_t);
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
	if (offset < 0)
		i = -offset;
	while (++i < x_len[1] && i + offset < c_ray->screen_h)
	{
		get_pixel(texture, texture_x, i / texture_ratio, &color);
		color = shadow(color, (15 - c_ray->all_distances[x_len[0]]) / 15);
		if (i + offset >= 0)
			draw_pixel(c_ray, x_len[0], i + offset, color);
	}
	i--;
	while (++i + offset < c_ray->screen_h)
	{
		color = c_ray->c_map->floor_t;
		color = shadow(c_ray->c_map->floor_t, ((float)(i + offset - c_ray->look_offset)
					- c_ray->screen_h / 2 - 26) / c_ray->screen_h * 2);
		if (i + offset >= 0)
			draw_pixel(c_ray, x_len[0], i + offset, color);
	}
}

void	draw_sprite(t_ray *c_ray, t_sprite_list *c_list)
{
	int		i;
	int		j;
	int		color;
	float	ratio;

	while (c_list)
	{
		ratio = (float)c_list->content->height / c_list->content->img->height;
		i = c_list->content->start_y - 1;
		while (++i < c_list->content->end_y)
		{
			j = c_list->content->start_x - 1;
			while (++j < c_list->content->end_x)
			{
				get_pixel(c_list->content->img, (j - c_list->content->start_x + c_list->content->offset_x) / ratio, (i - c_list->content->start_y + c_list->content->offset_y) / ratio, &color);
				if (color != 1193046 && c_list->content->distance < c_ray->all_distances[j])
				{
					color = shadow(color, (15 - c_list->content->distance) / 15);
					draw_pixel(c_ray, j, i, color);
				}
			}
		}
		c_list = c_list->next;
	}
}
