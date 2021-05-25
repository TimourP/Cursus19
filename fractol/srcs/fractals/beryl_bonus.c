/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beryl_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:39:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 21:03:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

static void	beryl_loop(t_calc *c)
{
	c->atmp = (c->xa * c->za - c->xb * c->zb);
	c->btmp = (c->xa * c->zb + c->xb * c->za);
	c->xa = c->k * (c->xa + c->za);
	c->xb = c->k * (c->xb + c->zb);
	c->za = c->atmp;
	c->zb = c->btmp;
	c->count++;
}

void	*beryl(void *thread)
{
	t_thread	*thr;
	t_calc		c;

	thr = thread;
	c.k = 1;
	c.y = -1;
	c.x_scale = thr->x_side / WINDOW_WIDTH;
	c.y_scale = thr->y_side / WINDOW_HEIGHT;
	while (++c.i < WINDOW_WIDTH * WINDOW_HEIGHT / THREAD_COUNT)
	{
		c.x = (c.i * THREAD_COUNT + thr->id) % WINDOW_WIDTH;
		c.y = (c.i * THREAD_COUNT + thr->id) / WINDOW_WIDTH;
		c.count = 0;
		c.xa = c.x * c.x_scale + thr->left;
		c.xb = c.y * c.y_scale + thr->top;
		c.za = 1;
		c.zb = 0;
		while ((c.k * (c.xa + c.za) <= 4) && (c.count < MAX_COUNT))
			beryl_loop(&c);
		c.color = (MAX_COUNT - c.count) * 1000;
		if (c.color != 0)
			c.color = c.color + 14942208 + thr->color_add;
		draw_pixel(thr->mlx_img, c.x, c.y, c.color);
	}
}
