/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:55:16 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/01 15:00:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		draw_pixel(t_ray *c_ray, int x, int y, int color)
{
	char	*dst;

	dst = c_ray->img_addr + (y * c_ray->img_line_l + x * (c_ray->img_bpp / 8));
	*(unsigned int*)dst = color;
}

void		draw_rectangle(t_ray *c_ray, int xy[2], int width_height[2], int color)
{
	int			i;
	int			j;
	const int	screen_height = c_ray->screen_h;
	const int	screen_width = c_ray->screen_w;

	i = -1;
	while (++i < width_height[1] && i + xy[1] < screen_height && xy[1] >= 0)
	{
		j = -1;
		while (++j < width_height[0] && j + xy[0] < screen_width && xy[0] >= 0)
		{
			draw_pixel(c_ray, j + xy[0], i + xy[1], color);
		}
	}
}
