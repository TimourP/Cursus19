/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:55:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 13:00:31 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	init_const(t_fract *fract, t_calc *c)
{
	c->y = -1;
	c->x_scale = fract->x_side / WINDOW_WIDTH;
	c->y_scale = fract->y_side / WINDOW_HEIGHT;
	c->ca = (float)(4 * fract->mouse_x) / WINDOW_WIDTH - 2;
	c->cb = (float)(4 * fract->mouse_y) / WINDOW_HEIGHT - 2;
	if (!BONUS)
	{
		c->ca = 0.285;
		c->cb = 0.01;
	}
}

void	julia(t_fract *fract)
{
	t_calc	c;

	init_const(fract, &c);
	while (++c.y < WINDOW_HEIGHT)
	{
		c.x = -1;
		while (++c.x < WINDOW_WIDTH)
		{
			c.za = c.x * c.x_scale + fract->left;
			c.zb = c.y * c.y_scale + fract->top;
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
				c.color = c.color + 14942208 + fract->color_add;
			draw_pixel(fract->mlx_img, c.x, c.y, c.color);
		}
	}
}
