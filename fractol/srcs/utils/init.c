/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:52:00 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 14:36:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	exit_hook(t_fract *fract)
{
	free_on_error(fract, CLOSE_WINDOW);
	return (0);
}

static void	init_fract(t_fract *fract)
{
	fract->mouse_x = 0;
	fract->mouse_y = 0;
	fract->top = -0.75;
	fract->y_side = 1.5;
	fract->left = -2;
	fract->x_side = 4;
	fract->up_move = 0;
	fract->down_move = 0;
	fract->right_move = 0;
	fract->left_move = 0;
	fract->zoom_on = 0;
	fract->zoom_off = 0;
	fract->color = 0;
}

static void	init_exit(t_fract *fract, int mlx_too)
{
	if (mlx_too)
		free(fract->mlx_img);
	free(fract);
	exit_message(MALLOC_ERROR);
}

void	init_mlx(t_fract *fract)
{
	init_fract(fract);
	fract->mlx_ptr = mlx_init();
	fract->mlx_win = mlx_new_window(fract->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FRACTOL");
	fract->mlx_img = malloc(sizeof(t_image));
	if (!fract->mlx_img)
		init_exit(fract, 0);
	fract->mlx_img->mlx_img = mlx_new_image(fract->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fract->mlx_img->mlx_img)
		init_exit(fract, 1);
	fract->mlx_img->addr = mlx_get_data_addr(fract->mlx_img->mlx_img,
			&fract->mlx_img->bpp,
			&fract->mlx_img->line_l, &fract->mlx_img->edian);
	mlx_hook(fract->mlx_win, 2, 1L << 0, key_press, fract);
	mlx_hook(fract->mlx_win, 3, 1L << 1, key_release, fract);
	mlx_hook(fract->mlx_win, 6, 1L << 6, move_mouse, fract);
	mlx_hook(fract->mlx_win, 17, 1L << 17, exit_hook, fract);
	mlx_hook(fract->mlx_win, 4, 1L << 2, mouse_wheel, fract);
	mlx_loop_hook(fract->mlx_ptr, next_frame, fract);
	mlx_loop(fract->mlx_ptr);
}
