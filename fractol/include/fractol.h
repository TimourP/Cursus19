/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:18:19 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 18:32:30 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

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

typedef struct s_fract
{
	int		id;
	t_image	*mlx_img;
	void	*mlx_ptr;
	void	*mlx_win;
	long double	top;
	long double	left;
	long double	x_side;
	long double	y_side;
	int		right_move;
	int		left_move;
	int		up_move;
	int		down_move;
	int		zoom_on;
	int		zoom_off;
	int		mouse_x;
	int		mouse_y;
}				t_fract;

/*
** MACROS
*/

# define PI 3.1415926535

# define WINDOW_WIDTH 540
# define WINDOW_HEIGHT 360

# define KEY_ESC 53
# define KEY_UP_ARROW 126
# define KEY_DOWN_ARROW 125
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_UP_MOVE 13
# define KEY_DOWN_MOVE 1
# define KEY_LEFT_MOVE 0
# define KEY_RIGHT_MOVE 2
# define KEY_SPACE 49
# define KEY_ALT 261

# define KEY_MOVE 0.05

# define ARG_ERROR 0
# define MALLOC_ERROR 1
# define FRACTAL_NAME_ERROR 2
# define CLOSE_WINDOW 3

# define MAX_COUNT 255
# define ZOOM_VALUE 0.9
# define THREAD_COUNT 16

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

void	mandelbrot(t_fract *fract);
void	julia(t_fract *fract);

#endif