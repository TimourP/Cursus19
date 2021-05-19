/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:02:08 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 18:26:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	proceed_moves(t_fract *fract)
{
	if (fract->zoom_on)
	{
		fract->x_side = fract->x_side * 0.9;
		fract->y_side = fract->y_side * 0.9;
		fract->left += fract->x_side * 0.05;
		fract->top += fract->y_side * 0.05;
	}
	if (fract->up_move)
		fract->top -= fract->y_side / 20;
	if (fract->down_move)
		fract->top += fract->y_side / 20;
	if (fract->left_move)
		fract->left -= fract->x_side / 20;
	if (fract->right_move)
		fract->left += fract->x_side / 20;
}

int	next_frame(t_fract *fract)
{
	static long double	last_left;
	static long double	last_top;

	proceed_moves(fract);
	if (last_left != fract->left || last_top != fract->top)
	{
		last_top = fract->top;
		last_left = fract->left;
		printf("New frame\n");
		if (fract->id == 0)
			julia(fract);
		else if (fract->id == 1)
			mandelbrot(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win, fract->mlx_img->mlx_img, 0, 0);
	}
	return (0);
}
