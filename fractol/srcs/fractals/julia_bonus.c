/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:12:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/20 15:16:39 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

void	*julia(void *thread)
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
	ca = (float)(4 * thr->mouse_x) / WINDOW_WIDTH - 2;
	cb = (float)(4 * thr->mouse_y) / WINDOW_HEIGHT - 2;
	i = -1;
	while (++i < WINDOW_WIDTH * WINDOW_HEIGHT / THREAD_COUNT)
	{
		x = (i * THREAD_COUNT + thr->id) % WINDOW_WIDTH;
		y = (i * THREAD_COUNT + thr->id) / WINDOW_WIDTH;
		za = x * x_scale + thr->left;
		zb = y * y_scale + thr->top;
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
		draw_pixel(thr->mlx_img, x, y, color);
	}
	return (NULL);
}