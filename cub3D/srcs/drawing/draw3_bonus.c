/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:55:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/03 12:04:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
