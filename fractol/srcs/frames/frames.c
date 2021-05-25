/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:02:08 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 21:00:48 by tpetit           ###   ########.fr       */
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
	if (fract->up_move)
		fract->top -= fract->y_side / 20;
	if (fract->down_move)
		fract->top += fract->y_side / 20;
	if (fract->left_move)
		fract->left -= fract->x_side / 20;
	if (fract->right_move)
		fract->left += fract->x_side / 20;
	if (fract->color)
		fract->color_add += 1000;
	if (fract->up_move || fract->down_move || fract->left_move
		|| fract->right_move || fract->color)
		change = 1;
	return (change);
}

int	next_frame(t_fract *fract)
{
	static int	init;

	if (proceed_moves(fract) || !init)
	{
		if (!init)
			init = 1;
		printf("New frame\n");
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
