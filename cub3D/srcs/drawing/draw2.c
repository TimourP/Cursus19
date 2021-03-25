/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:11:45 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/25 12:12:47 by tpetit           ###   ########.fr       */
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
