/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:58:33 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 20:58:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	move_mouse(int x, int y, t_fract *fract)
{
	if (x >= 0 && y >= 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		fract->mouse_x = x;
		fract->mouse_y = y;
	}
	return (0);
}

int	key_press(int key, t_fract *fract)
{
	if (key == KEY_ESC)
		free_on_error(fract, CLOSE_WINDOW);
	else if (key == KEY_RIGHT_ARROW)
		fract->right_move = 1;
	else if (key == KEY_LEFT_ARROW)
		fract->left_move = 1;
	else if (key == KEY_UP_ARROW)
		fract->up_move = 1;
	else if (key == KEY_DOWN_ARROW)
		fract->down_move = 1;
	else if (key == KEY_SPACE)
		fract->color = 1;
	return (0);
}

int	key_release(int key, t_fract *fract)
{
	if (key == KEY_ESC)
		free_on_error(fract, CLOSE_WINDOW);
	else if (key == KEY_RIGHT_ARROW)
		fract->right_move = 0;
	else if (key == KEY_LEFT_ARROW)
		fract->left_move = 0;
	else if (key == KEY_UP_ARROW)
		fract->up_move = 0;
	else if (key == KEY_DOWN_ARROW)
		fract->down_move = 0;
	else if (key == KEY_SPACE)
		fract->color = 0;
	return (0);
}

int	mouse_wheel(int btn, int x, int y, t_fract *fract)
{
	x = (int)x;
	y = (int)y;
	if (btn == 5)
		fract->zoom_on = 1;
	else if (btn == 4)
		fract->zoom_off = 1;
	return (0);
}
