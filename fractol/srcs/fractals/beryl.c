/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beryl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:34:00 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 13:04:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

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

void	beryl(t_fract *fract)
{
	t_calc	c;

	c.k = 1;
	c.y = -1;
	c.x_scale = fract->x_side / WINDOW_WIDTH;
	c.y_scale = fract->y_side / WINDOW_HEIGHT;
	while (++c.y < WINDOW_HEIGHT)
	{
		c.x = -1;
		while (++c.x < WINDOW_WIDTH)
		{
			c.count = 0;
			c.xa = c.x * c.x_scale + fract->left;
			c.xb = c.y * c.y_scale + fract->top;
			c.za = 1;
			c.zb = 0;
			while ((c.k * (c.xa + c.za) <= 4) && (c.count < MAX_COUNT))
				beryl_loop(&c);
			c.color = (MAX_COUNT - c.count) * 3000;
			if (c.color != 0)
				c.color = c.color + 14942208 + fract->color_add;
			draw_pixel(fract->mlx_img, c.x, c.y, c.color);
		}
	}
}
