/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:11:45 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 15:09:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_line(t_ray *c_ray, int x_y_l[3], float angle, const int color)
{
	float	dx;
	float	dy;
	int		i;

	i = -1;
	dx = cos(-angle);
	dy = sin(-angle);
	if (x_y_l[2] > 80)
		x_y_l[2] = 80;
	while (++i < x_y_l[2])
		draw_pixel(c_ray, x_y_l[0] + (i * dx), x_y_l[1] - (i * dy), color);
}

void	draw_vertical_line(t_ray *c_ray, const int x,
	const int length, const int color)
{
	int			i;
	const int	offset = (c_ray->screen_h - length) / 2;

	i = -1;
	while (++i < length && i + offset < c_ray->screen_h)
	{
		draw_pixel(c_ray, x, i + offset, color);
	}
	i--;
	while (++i + offset < c_ray->screen_h)
	{
		draw_pixel(c_ray, x, i + offset, c_ray->c_map->ceiling_t);
	}
}
