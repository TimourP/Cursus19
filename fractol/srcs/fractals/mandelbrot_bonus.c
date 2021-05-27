/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:41:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 13:04:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

static void	mandelbrot_var(t_thread *thr, t_calc *c)
{
	c->x = (c->i * THREAD_COUNT + thr->id) % WINDOW_WIDTH;
	c->y = (c->i * THREAD_COUNT + thr->id) / WINDOW_WIDTH;
	c->ca = c->x * c->x_scale + thr->left;
	c->cb = c->y * c->y_scale + thr->top;
	c->za = 0;
	c->zb = 0;
	c->count = 0;
}

void	*mandelbrot(void *thread)
{
	t_calc		c;
	t_thread	*thr;

	thr = thread;
	c.y = -1;
	c.x_scale = thr->x_side / WINDOW_WIDTH;
	c.y_scale = thr->y_side / WINDOW_HEIGHT;
	c.i = -1;
	while (++c.i < WINDOW_WIDTH * WINDOW_HEIGHT / THREAD_COUNT)
	{
		mandelbrot_var(thr, &c);
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
