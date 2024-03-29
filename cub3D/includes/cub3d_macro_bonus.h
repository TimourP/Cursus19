/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_macro_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:36:33 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/20 11:22:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MACRO_BONUS_H
# define CUB3D_MACRO_BONUS_H

# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define CROSS_BTN_EVENT 17

# define PLAYER_SPEED 3
# define LIFE_DECREASE_RATE 10
# define PLAYER_ROTATION 0.05
# define OFFSET_SPEED 20
# define MAX_OFFSET 400

# define PI 3.1415926535
# define FOV 3.5

# define MINI_SQUARE 8
# define MINI_WIDTH 320
# define MINI_HEIGHT 240

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

# define COLOR_RED 0x00E74C3C
# define COLOR_BLACK 0x00000000
# define COLOR_WHITE 0x00FFFFFF
# define COLOR_BLUE 0x005DADE2
# define COLOR_YELLOW 0x00F1C40F
# define COLOR_MINIMAP_WALKABLE 0x00B3B6B7
# define COLOR_MINIMAP_WALL 0x00A04000
# define COLOR_MONSTERS 0x00D81B60

# define MAP_ERROR 0
# define MALLOC_ERROR 1
# define FILE_ERROR 2
# define PARSING_ERROR 3
# define GBV_OVERFLOW 4
# define MULTIPLE_SAME_LINES 5
# define BPM_ERROR 6

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef LIGHT
#  define LIGHT 0
# endif

#endif