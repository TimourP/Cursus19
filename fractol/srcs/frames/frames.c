/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:02:08 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 11:53:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	next_frame(t_fract *fract)
{
	static int	last_mouse;

	if (last_mouse != fract->mouse_value + 1)
	{
		last_mouse = fract->mouse_value + 1;
		mandelbrot(fract);
		mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win, fract->mlx_img->mlx_img, 0, 0);
	}
	return (0);
}
