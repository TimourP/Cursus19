/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:23:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 12:07:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	mandelbrot(t_fract *fract)
{
	int 	x;
	int		y;
	int		count;
	double	x_scale;
	double	y_scale;
	double	zx, zy, cx, tempx, cy;
	int		color;

	y = -1;
	x_scale = fract->x_side / WINDOW_WIDTH;
	y_scale = fract->y_side / WINDOW_HEIGHT;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			cx = x * x_scale + fract->left;
			cy = y * y_scale + fract->top;
			zx = 0;
			zy = 0;
			count = 0;
			while ((zx * zx + zy * zy < 4) && (count < MAX_COUNT))
			{
				tempx = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = tempx;
				count++;
			}
			color = (MAX_COUNT - count) * 500;
			color = color == 0 ? 0 : color + 14942208;
			draw_pixel(fract->mlx_img, x, y, color);
		}
	}
}