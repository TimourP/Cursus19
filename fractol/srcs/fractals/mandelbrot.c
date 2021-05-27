/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:23:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 13:03:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	mandelbrot_var(t_fract *fract, t_calc *c)
{
	c->ca = c->x * c->x_scale + fract->left;
	c->cb = c->y * c->y_scale + fract->top;
	c->za = 0;
	c->zb = 0;
	c->count = 0;
}

void	mandelbrot(t_fract *fract)
{
	t_calc	c;

	c.y = -1;
	c.x_scale = fract->x_side / WINDOW_WIDTH;
	c.y_scale = fract->y_side / WINDOW_HEIGHT;
	while (++c.y < WINDOW_HEIGHT)
	{
		c.x = -1;
		while (++c.x < WINDOW_WIDTH)
		{
			mandelbrot_var(fract, &c);
			while ((c.za * c.za + c.zb * c.zb <= 4) && (c.count < MAX_COUNT))
			{
				c.tempx = c.za * c.za - c.zb * c.zb + c.ca;
				c.zb = 2 * c.za * c.zb + c.cb;
				c.za = c.tempx;
				c.count++;
			}
			c.color = (MAX_COUNT - c.count) * 3000;
			if (c.color)
				c.color = c.color + 14942208 + fract->color_add;
			draw_pixel(fract->mlx_img, c.x, c.y, c.color);
		}
	}
}
