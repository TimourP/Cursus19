/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:18:19 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 10:28:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>


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

/*
** MACROS
*/

# define PI 3.1415926535

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 720

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

# define ARG_ERROR 0
# define MALLOC_ERROR 1
# define FRACTAL_NAME_ERROR 2

/*
** DRAW
*/


/*
** UTILS
*/

void	exit_message(int message);

#endif