/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:18:19 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 20:44:16 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include "fractol_macros.h"

# include <pthread.h>

# include <stdio.h>

/*
** STRUCTS
*/

typedef struct s_image
{
	void		*mlx_img;
	char		*addr;
	char		*path;
	int			bpp;
	int			line_l;
	int			edian;
	int			width;
	int			height;
}				t_image;

typedef struct s_thread
{
	t_image		*mlx_img;
	long double	top;
	long double	left;
	long double	x_side;
	long double	y_side;
	int			mouse_x;
	int			mouse_y;
	int			id;
}				t_thread;

typedef struct s_fract
{
	int			id;
	t_image		*mlx_img;
	void		*mlx_ptr;
	void		*mlx_win;
	long double	top;
	long double	left;
	long double	x_side;
	long double	y_side;
	int			right_move;
	int			left_move;
	int			up_move;
	int			down_move;
	int			zoom_on;
	int			zoom_off;
	int			mouse_x;
	int			mouse_y;
}				t_fract;

typedef struct s_calc
{
	int 		x;
	int			y;
	int			count;
	long double	x_scale;
	long double	y_scale;
	long double	za;
	long double	zb;
	long double	ca;
	long double	tempx;
	long double	cb;
	long double	k;
	long double	xa;
	long double	xb;
	long double	atmp;
	long double	btmp;
	int			color;
	int			i;
}				t_calc;

/*
** DRAW
*/

void	draw_pixel(t_image *img, int x, int y, int color);
int		create_rgb(int r, int g, int b);

/*
** UTILS
*/

void	exit_message(int message);
void	init_mlx(t_fract *fract);
void	free_on_error(t_fract *fract, int message);

/*
** frames
*/

int		next_frame(t_fract *fract);
int		move_mouse(int x, int y, t_fract *fract);
int		key_release(int key, t_fract *fract);
int		key_press(int key, t_fract *fract);
int		mouse_wheel(int btn, int x, int y, t_fract *fract);

/*
**	fractals
*/

void	*mandelbrot(void *thread);
void	*julia(void *thread);
void	*beryl(void *thread);

#endif