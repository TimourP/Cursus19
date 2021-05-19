/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:55:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 14:53:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	julia(t_fract *fract)
{
	int 	x;
	int		y;
	int		count;
	double	x_scale;
	double	y_scale;
	double	za, zb, ca, tempx, cb;
	int		color;

	y = -1;
	x_scale = fract->x_side / WINDOW_WIDTH;
	y_scale = fract->y_side / WINDOW_HEIGHT;
	ca = (float)(4 * fract->mouse_x) / WINDOW_WIDTH - 2;
	cb = (float)(4 * fract->mouse_y) / WINDOW_HEIGHT - 2;
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