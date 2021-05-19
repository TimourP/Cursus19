/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:41:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 18:26:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

void	mandelbrot(void *thread)
{
	int 	x;
	int		y;
	int		count;
	long double	x_scale;
	long double	y_scale;
	long double	za, zb, ca, tempx, cb;
	int		color;
	t_thread	*thr;
	int i;

	thr = thread;
	y = -1;
	x_scale = thr->x_side / WINDOW_WIDTH;
	y_scale = thr->y_side / WINDOW_HEIGHT;
	i = -1;
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT / THREAD_COUNT)
	{
		x = (i * THREAD_COUNT + thr->id) % WINDOW_WIDTH;
		y = (i * THREAD_COUNT + thr->id) / WINDOW_WIDTH;
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
		color = (MAX_COUNT - count) * 1000;
		color = color == 0 ? 0 : color;
		draw_pixel(thr->mlx_img, x, y, color);
	}
}