/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_macros.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:31:25 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/31 11:59:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MACROS_H
# define FRACTOL_MACROS_H

# define PI 3.1415926535

# define WINDOW_WIDTH 192
# define WINDOW_HEIGHT 108

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
# define THREAD_COUNT 8

# ifndef BONUS
#  define BONUS 0
# endif

#endif