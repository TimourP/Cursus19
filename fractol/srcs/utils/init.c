/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:52:00 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 11:58:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int		exit_hook(t_fract *fract)
{
	free_on_error(fract, CLOSE_WINDOW);
	return (0);
}

static void	init_fract(t_fract *fract)
{
	fract->mouse_value = 0;
	fract->top = -0.75;
	fract->y_side = 1.5;
	fract->left = -2;
	fract->x_side = 4;
}

void	init_mlx(t_fract *fract)
{
	init_fract(fract);
	fract->mlx_ptr = mlx_init();
	fract->mlx_win = mlx_new_window(fract->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FRACTOL");
	fract->mlx_img = malloc(sizeof(t_image));
	fract->mlx_img->mlx_img = mlx_new_image(fract->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	fract->mlx_img->addr = mlx_get_data_addr(fract->mlx_img->mlx_img, &fract->mlx_img->bpp,
			&fract->mlx_img->line_l, &fract->mlx_img->edian);
	mlx_hook(fract->mlx_win, 6, 1L << 6, move_mouse, fract);
	mlx_hook(fract->mlx_win, 17, 1L << 17, exit_hook, fract);
	mlx_loop_hook(fract->mlx_ptr, next_frame, fract);
	mlx_loop(fract->mlx_ptr);
}
