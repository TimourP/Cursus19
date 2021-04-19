/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:55:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/19 12:08:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	quit_properly(t_ray *c_ray)
{
	mlx_destroy_window(c_ray->mlx_ptr, c_ray->mlx_win);
	free_t_map(c_ray->c_map);
	exit(0);
}

int	key_press(int key, t_ray *c_ray)
{
	if (key == KEY_ESC)
		quit_properly(c_ray);
	if (key == KEY_UP_MOVE)
		c_ray->go_forward = 1;
	else if (key == KEY_DOWN_MOVE)
		c_ray->go_backward = 1;
	else if (key == KEY_LEFT_MOVE)
		c_ray->go_left = 1;
	else if (key == KEY_RIGHT_MOVE)
		c_ray->go_right = 1;
	else if (key == KEY_RIGHT_ARROW)
		c_ray->turn_right = 1;
	else if (key == KEY_LEFT_ARROW)
		c_ray->turn_left = 1;
	else if (key == KEY_UP_ARROW)
		c_ray->look_up = 1;
	else if (key == KEY_DOWN_ARROW)
		c_ray->look_down = 1;
	else if (key == KEY_ALT)
		c_ray->look_offset = -100;
	return (1);
}

int	key_release(int key, t_ray *c_ray)
{
	if (key == KEY_UP_MOVE)
		c_ray->go_forward = 0;
	else if (key == KEY_DOWN_MOVE)
		c_ray->go_backward = 0;
	else if (key == KEY_LEFT_MOVE)
		c_ray->go_left = 0;
	else if (key == KEY_RIGHT_MOVE)
		c_ray->go_right = 0;
	else if (key == KEY_RIGHT_ARROW)
		c_ray->turn_right = 0;
	else if (key == KEY_LEFT_ARROW)
		c_ray->turn_left = 0;
	else if (key == KEY_UP_ARROW)
		c_ray->look_up = 0;
	else if (key == KEY_DOWN_ARROW)
		c_ray->look_down = 0;
	else if (key == KEY_ALT)
		c_ray->look_offset = 0;
	return (1);
}

int	exit_button(t_ray *c_ray)
{
	return (quit_properly(c_ray));
}
