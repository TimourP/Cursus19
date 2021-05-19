/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:49:54 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 18:26:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol_bonus.h"

void	proceed_moves(t_fract *fract)
{
	static int count;
	if (fract->zoom_on)
	{
		count++;
		printf("%d\n", count);
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
	int				i;
	pthread_t		t_id[THREAD_COUNT];
	t_thread		threads[THREAD_COUNT];

	proceed_moves(fract);
	if (last_left != fract->left || last_top != fract->top)
	{
		last_top = fract->top;
		last_left = fract->left;
		i = -1;
		while (++i < THREAD_COUNT)
		{
			threads[i].id = i;
			threads[i].left = fract->left;
			threads[i].top = fract->top;
			threads[i].x_side = fract->x_side;
			threads[i].y_side = fract->y_side;
			threads[i].mlx_img = fract->mlx_img;
			pthread_create(&t_id[i], NULL, mandelbrot, &threads[i]);
		}
		i = -1;
		while (++i < THREAD_COUNT)
			pthread_join(t_id[i], NULL);
		/*if (fract->id == 0)
			julia(fract);
		else if (fract->id == 1)
			mandelbrot(fract);*/
		mlx_put_image_to_window(fract->mlx_ptr, fract->mlx_win, fract->mlx_img->mlx_img, 0, 0);
	}
	return (0);
}
