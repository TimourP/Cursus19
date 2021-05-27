/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:02:08 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 12:31:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	zoom_on(t_fract *fract, int *change)
{
	fract->left += fract->x_side * 0.05;
	fract->top += fract->y_side * 0.05;
	fract->x_side = fract->x_side * 0.9;
	fract->y_side = fract->y_side * 0.9;
	fract->zoom_on = 0;
	*change = 1;
}

static void	zoom_out(t_fract *fract, int *change)
{
	fract->left -= fract->x_side * 0.05;
	fract->top -= fract->y_side * 0.05;
	fract->x_side = fract->x_side * 1.1;
	fract->y_side = fract->y_side * 1.1;
	fract->zoom_off = 0;
	*change = 1;
}

static int	proceed_moves(t_fract *fract)
{
	int	change;

	change = 0;
	if (fract->zoom_on)
		zoom_on(fract, &change);
	else if (fract->zoom_off)
		zoom_out(fract, &change);
	return (change);
}

int	next_frame(t_fract *fract)
{
	static int	init;
	static int	mouse_x;
	static int	mouse_y;

	if (proceed_moves(fract) || !init || ((mouse_x != fract->mouse_x
				|| mouse_y != fract->mouse_y) && fract->id == 0))
	{
		if (!init)
			init = 1;
		mouse_x = fract->mouse_x;
		mouse_y = fract->mouse_y;
		if (fract->id == 0)
			julia(fract);
		else if (fract->id == 1)
			mandelbrot(fract);
		else if (fract->id == 2)
			beryl(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win,
			fract->mlx_img->mlx_img, 0, 0);
	}
	return (0);
}
