/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:12:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 13:04:48 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

static void	init_const(t_thread *thread, t_calc *c)
{
	c->y = -1;
	c->i = -1;
	c->x_scale = thread->x_side / WINDOW_WIDTH;
	c->y_scale = thread->y_side / WINDOW_HEIGHT;
	c->ca = (float)(4 * thread->mouse_x) / WINDOW_WIDTH - 2;
	c->cb = (float)(4 * thread->mouse_y) / WINDOW_HEIGHT - 2;
}

void	*julia(void *thread)
{
	t_calc		c;
	t_thread	*thr;

	init_const(thread, &c);
	thr = thread;
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
		c.color = (MAX_COUNT - c.count) * 3000;
		if (c.color != 0)
			c.color = c.color + 14942208 + thr->color_add;
		draw_pixel(thr->mlx_img, c.x, c.y, c.color);
	}
	return (NULL);
}
