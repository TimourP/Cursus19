/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_macro.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:11:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/25 11:31:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MACRO_H
# define CUB3D_MACRO_H

# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define CROSS_BTN_EVENT 17

# define PLAYER_SPEED 0.1
# define PLAYER_ROTATION 0.05
# define OFFSET_SPEED 20
# define MAX_OFFSET 400

# define PI 3.1415926535
# define FOV 3

# define MINI_SQUARE 20
# define MINI_WIDTH 320
# define MINI_HEIGHT 240

# define CASE_WIDTH 40

# define KEY_ESC 53
# define KEY_UP_ARROW 126
# define KEY_DOWN_ARROW 125
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_UP_MOVE 13
# define KEY_DOWN_MOVE 1
# define KEY_LEFT_MOVE 0
# define KEY_RIGHT_MOVE 2

# define COLOR_RED 0x00E74C3C
# define COLOR_BLACK 0x00000000
# define COLOR_WHITE 0x00FFFFFF
# define COLOR_BLUE 0x005DADE2
# define COLOR_YELLOW 0x00F1C40F
# define COLOR_MINIMAP_WALKABLE 0x00B3B6B7
# define COLOR_MINIMAP_WALL 0x00A04000

# ifndef BONUS
# 	define BONUS 0
# endif

# ifndef LIGHT
# 	define LIGHT 0
# endif

#endif
