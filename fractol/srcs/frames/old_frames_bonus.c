/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_frames_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 12:22:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 13:04:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"
#include <pthread.h>

static void	zoom_on(t_fract *fract, int *change)
{
	fract->left += fract->x_side * 0.05;
	fract->top += fract->y_side * 0.05;
	fract->x_side = fract->x_side * 0.9;
	fract->y_side = fract->y_side * 0.9;
	fract->zoom_on = 0;
	*change = 1;
	if (fract->mouse_x - WINDOW_WIDTH / 2 < 0)
		fract->left -= fract->x_side * 0.1 * (1.0
				- (float)fract->mouse_x / (WINDOW_WIDTH / 2));
	else
		fract->left += fract->x_side * 0.1 * ((float)(fract->mouse_x
					- WINDOW_WIDTH / 2) / (WINDOW_WIDTH / 2));
	if (fract->mouse_y - WINDOW_HEIGHT / 2 < 0)
		fract->top -= fract->y_side * 0.1 * (1.0
				- (float)fract->mouse_y / (WINDOW_HEIGHT / 2));
	else
		fract->top += fract->y_side * 0.1 * ((float)(fract->mouse_y
					- WINDOW_HEIGHT / 2) / (WINDOW_HEIGHT / 2));
}

static void	zoom_out(t_fract *fract, int *change)
{
	fract->left -= fract->x_side * 0.05;
	fract->top -= fract->y_side * 0.05;
	fract->x_side = fract->x_side * 1.1;
	fract->y_side = fract->y_side * 1.1;
	fract->zoom_off = 0;
	*change = 1;
	if (fract->mouse_x - WINDOW_WIDTH / 2 < 0)
		fract->left += fract->x_side * 0.1 * (1.0
				- (float)fract->mouse_x / (WINDOW_WIDTH / 2));
	else
		fract->left -= fract->x_side * 0.1 * ((float)(fract->mouse_x
					- WINDOW_WIDTH / 2) / (WINDOW_WIDTH / 2));
	if (fract->mouse_y - WINDOW_HEIGHT / 2 < 0)
		fract->top += fract->y_side * 0.1 * (1.0
				- (float)fract->mouse_y / (WINDOW_HEIGHT / 2));
	else
		fract->top -= fract->y_side * 0.1 * ((float)(fract->mouse_y
					- WINDOW_HEIGHT / 2) / (WINDOW_HEIGHT / 2));
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

static void	init_threads(t_fract *fract, pthread_t t_id[THREAD_COUNT],
	t_thread threads[THREAD_COUNT])
{
	int	i;

	i = -1;
	while (++i < THREAD_COUNT)
	{
		threads[i].id = i;
		threads[i].left = fract->left;
		threads[i].top = fract->top;
		threads[i].x_side = fract->x_side;
		threads[i].y_side = fract->y_side;
		threads[i].mlx_img = fract->mlx_img;
		threads[i].mouse_y = fract->mouse_y;
		threads[i].mouse_x = fract->mouse_x;
		threads[i].color_add = fract->color_add;
		if (fract->id == 0)
			pthread_create(&t_id[i], NULL, julia, (void *)&threads[i]);
		else if (fract->id == 1)
			pthread_create(&t_id[i], NULL, mandelbrot, (void *)&threads[i]);
		else if (fract->id == 2)
			pthread_create(&t_id[i], NULL, beryl, (void *)&threads[i]);
	}
}

int	next_frame(t_fract *fract)
{
	static int	mouse_xy[2];
	static int	init;
	int			i;
	pthread_t	t_id[THREAD_COUNT];
	t_thread	threads[THREAD_COUNT];

	if (proceed_moves(fract) || !init || ((mouse_xy[0] != fract->mouse_x
				|| mouse_xy[1] != fract->mouse_y) && fract->id == 0))
	{
		if (!init)
			init = 1;
		mouse_xy[0] = fract->mouse_x;
		mouse_xy[1] = fract->mouse_y;
		init_threads(fract, t_id, threads);
		i = -1;
		while (++i < THREAD_COUNT)
			pthread_join(t_id[i], NULL);
		mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win,
			fract->mlx_img->mlx_img, 0, 0);
	}
	return (0);
}
