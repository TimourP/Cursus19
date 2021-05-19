/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:55:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 18:26:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	julia(t_fract *fract)
{
	int 	x;
	int		y;
	int		count;
	long double	x_scale;
	long double	y_scale;
	long double	za, zb, ca, tempx, cb;
	int		color;

	y = -1;
	x_scale = fract->x_side / WINDOW_WIDTH;
	y_scale = fract->y_side / WINDOW_HEIGHT;
	ca = 0.285;
	cb = 0.01;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			za = x * x_scale + fract->left;
			zb = y * y_scale + fract->top;
			count = 0;
			while ((za * za + zb * zb <= 4) && (count < MAX_COUNT))
			{
				tempx = za * za - zb * zb + ca;
				zb = 2 * za * zb + cb;
				za = tempx;
				count++;
			}
			color = (MAX_COUNT - count) * 1000;
			color = color == 0 ? 0 : color + 14942208;
			draw_pixel(fract->mlx_img, x, y, color);
		}
	}
}