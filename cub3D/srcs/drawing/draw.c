/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:55:16 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/31 16:16:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_pixel(t_ray *c_ray, int x, int y, int color)
{
	char	*dst;

	dst = c_ray->img_addr + (y * c_ray->img_line_l + x * (c_ray->img_bpp / 8));
	*(unsigned int *)dst = color;
}

void	get_pixel(t_image *image, int x, int y, int *color)
{
	char	*dst;

	dst = image->addr + (y * image->line_l + x * (image->bpp / 8));
	*color = *(unsigned int *)dst;
}

void	draw_rectangle(t_ray *c_ray, const int xy[2],
			const int width_height[2], const int color)
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
			if (0 && (i == 0 || j == 0))
				draw_pixel(c_ray, j + xy[0], i + xy[1], COLOR_BLACK);
			else
				draw_pixel(c_ray, j + xy[0], i + xy[1], color);
		}
	}
}

void	draw_player(t_ray *c_ray, const int xy_wh[4],
			const int color, float angle)
{
	int			i;
	int			j;
	const int	screen_height = c_ray->screen_h;
	const int	screen_width = c_ray->screen_w;
	float		a_v[4];

	i = -1;
	angle = angle + PI / 2;
	while (++i < xy_wh[3] && i + xy_wh[1] < screen_height && xy_wh[1] >= 0)
	{
		j = -1;
		while (++j < xy_wh[2] && j + xy_wh[0] < screen_width && xy_wh[0] >= 0)
		{
			if (i + j > xy_wh[2] / 2 && !(j - i + 2 > xy_wh[2] / 2))
			{
				a_v[0] = j + xy_wh[0] - xy_wh[2] / 2;
				a_v[1] = i + xy_wh[1] - xy_wh[3] / 2;
				a_v[2] = a_v[0] - xy_wh[0];
				a_v[3] = a_v[1] - xy_wh[1];
				a_v[0] = xy_wh[0] + a_v[2] * cos(angle) - a_v[3] * sin(angle);
				a_v[1] = xy_wh[1] + a_v[2] * sin(angle) + a_v[3] * cos(angle);
				draw_pixel(c_ray, a_v[0], a_v[1], color);
			}
		}
	}
}

void	draw_empty_rectangle(t_ray *c_ray, const int xy_wh[4],
			const int color, const int inner_width)
{
	int			i;
	int			j;
	const int	screen_height = c_ray->screen_h;
	const int	screen_width = c_ray->screen_w;

	i = -1 + inner_width * 0;
	while (++i < xy_wh[3] && i + xy_wh[1] < screen_height && xy_wh[1] >= 0)
	{
		j = -1;
		while (++j < xy_wh[2] && j + xy_wh[0] < screen_width && xy_wh[0] >= 0)
		{
			if (i < inner_width || j < inner_width
				|| j > xy_wh[2] - inner_width || i > xy_wh[3] - inner_width)
				draw_pixel(c_ray, j + xy_wh[0], i + xy_wh[1], color);
		}
	}
}

void	draw_circle(t_ray *c_ray, const int xy[2],
			const int radius, const int color)
{
	int			i;
	int			j;
	const int	screen_height = c_ray->screen_h;
	const int	screen_width = c_ray->screen_w;

	i = -1;
	while (++i < radius * 2 && i + xy[1] < screen_height && xy[1] >= 0)
	{
		j = -1;
		while (++j < radius * 2 && j + xy[0] < screen_width && xy[0] >= 0)
		{
			if (pow(j - radius, 2) + pow(i - radius, 2) <= pow(radius, 2))
				draw_pixel(c_ray, j + xy[0], i + xy[1], color);
		}
	}
}
