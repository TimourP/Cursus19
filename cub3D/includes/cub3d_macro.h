/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_macro.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:11:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/04 10:06:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MACRO_H
# define CUB3D_MACRO_H

# define KEY_PRESS_EVENT 2
# define CROSS_BTN_EVENT 17

# define PLAYER_SPEED 1
# define PLAYER_ROTATION 0.2 * PI

# define MINI_SQUARE CASE_WIDTH
# define MINI_WIDTH 400
# define MINI_HEIGHT 200

# define CASE_WIDTH 20

# define KEY_ESC 53
# define KEY_UP_ARROW 126
# define KEY_DOWN_ARROW 125
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_UP_MOVE 13
# define KEY_DOWN_MOVE 1
# define KEY_LEFT_MOVE 0
# define KEY_RIGHT_MOVE 2

# define COLOR_RED 0x00FF0000
# define COLOR_BLACK 0x00000000
# define COLOR_WHITE 0x00FFFFFF
# define COLOR_MINIMAP_WALKABLE 0x00B3B6B7
# define COLOR_MINIMAP_WALL 0x00DC7633

# define PI 3.1415926535

#endif
