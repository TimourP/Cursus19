/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:41:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 16:40:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

void	mandelbrot(void *thread)
{
	int 	x;
	int		y;
	int		count;
	double	x_scale;
	double	y_scale;
	double	za, zb, ca, tempx, cb;
	int		color;
	t_thread	*thr;
	int i;

	thr = thread;
	y = -1;
	x_scale = thr->x_side / WINDOW_WIDTH;
	y_scale = thr->y_side / WINDOW_HEIGHT;
	i = -1;
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT / 16)
	{
		x = (i * 16 + thr->id) % WINDOW_WIDTH;
		y = (i * 16 + thr->id) / WINDOW_WIDTH;
		ca = x * x_scale + thr->left;
		cb = y * y_scale + thr->top;
		za = 0;
		zb = 0;
		count = 0;
		while ((za * za + zb * zb <= 4) && (count < MAX_COUNT))
		{
			tempx = za * za - zb * zb + ca;
			zb = 2 * za * zb + cb;
			za = tempx;
			count++;
		}
		color = (MAX_COUNT - count) * 100;
		color = color == 0 ? 0 : color + 14942208;
		draw_pixel(thr->mlx_img, x, y, color);
	}
}