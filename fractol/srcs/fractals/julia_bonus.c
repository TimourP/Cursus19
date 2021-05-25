/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:12:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 19:19:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

void	*julia(void *thread)
{
	t_calc		c;
	t_thread	*thr;

	thr = thread;
	c.y = -1;
	c.x_scale = thr->x_side / WINDOW_WIDTH;
	c.y_scale = thr->y_side / WINDOW_HEIGHT;
	c.ca = (float)(4 * thr->mouse_x) / WINDOW_WIDTH - 2;
	c.cb = (float)(4 * thr->mouse_y) / WINDOW_HEIGHT - 2;
	c.i = -1;
	while (++c.i < WINDOW_WIDTH * WINDOW_HEIGHT / THREAD_COUNT)
	{
		c.x = (c.i * THREAD_COUNT + thr->id) % WINDOW_WIDTH;
		c.y = (c.i * THREAD_COUNT + thr->id) / WINDOW_WIDTH;
		c.za = c.x * c.x_scale + thr->left;
		c.zb = c.y * c.y_scale + thr->top;
		c.count = 0;
		while ((c.za * c.za + c.zb * c.zb <= 4) && (c.count < MAX_COUNT))
		{
			c.tempx = c.za * c.za - c.zb * c.zb + c.ca;
			c.zb = 2 * c.za * c.zb + c.cb;
			c.za = c.tempx;
			c.count++;
		}
		c.color = (MAX_COUNT - c.count) * 1000;
		if (c.color != 0)
			c.color = c.color + 14942208;
		draw_pixel(thr->mlx_img, c.x, c.y, c.color);
	}
	return (NULL);
}
