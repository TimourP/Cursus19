/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:55:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/22 14:49:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_next_move(t_ray *c_ray, float x_diff, float y_diff)
{
	float	next_posx;
	float	next_posy;

	next_posx = c_ray->player_posx + x_diff;
	next_posy = c_ray->player_posy + y_diff;
	if (!is_in_str("0NSEW",
		c_ray->c_map->map[(int)next_posy][(int)next_posx]))
		return (0);
	return (1);
}

int		key_press(int key, t_ray *c_ray)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(c_ray->mlx_ptr, c_ray->mlx_win);
		exit(0);
	}
	if (key == 49)
	{
		printf("forward : %d\n", c_ray->go_forward);
		printf("backward : %d\n", c_ray->go_backward);
		printf("left : %d\n", c_ray->go_left);
		printf("right : %d\n", c_ray->go_right);
		printf("turn left : %d\n", c_ray->turn_left);
		printf("turm right : %d\n", c_ray->turn_right);
		
	}
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
	return (1);
}

int		key_release(int key, t_ray *c_ray)
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
	return (1);
}

int		get_next_frame(t_ray *c_ray)
{
	static float last_x;
	static float last_y;
	static float last_angle;

	if (c_ray->go_forward && check_next_move(c_ray, c_ray->player_dely, -c_ray->player_delx))
	{
		c_ray->player_posx += c_ray->player_dely;
		c_ray->player_posy -= c_ray->player_delx;
	}
	if (c_ray->go_backward && check_next_move(c_ray, -c_ray->player_dely, c_ray->player_delx))
	{
		c_ray->player_posx -= c_ray->player_dely;
		c_ray->player_posy += c_ray->player_delx;
	}
	if (c_ray->go_left && check_next_move(c_ray, -c_ray->player_delx, -c_ray->player_dely))
	{
		c_ray->player_posx -= c_ray->player_delx;
		c_ray->player_posy -= c_ray->player_dely;
	}
	if (c_ray->go_right && check_next_move(c_ray, c_ray->player_delx, c_ray->player_dely))
	{
		c_ray->player_posx += c_ray->player_delx;
		c_ray->player_posy += c_ray->player_dely;
	}
	if (c_ray->turn_right)
	{
		c_ray->player_angle += PLAYER_ROTATION;
		if (c_ray->player_angle > 2 * PI)
			c_ray->player_angle -= 2 * PI;
		c_ray->player_delx = cos(c_ray->player_angle) * PLAYER_SPEED;
		c_ray->player_dely = sin(c_ray->player_angle) * PLAYER_SPEED;
	}
	if (c_ray->turn_left)
	{
		c_ray->player_angle -= PLAYER_ROTATION;
		if (c_ray->player_angle < 0)
			c_ray->player_angle += 2 * PI;
		c_ray->player_delx = cos(c_ray->player_angle) * PLAYER_SPEED;
		c_ray->player_dely = sin(c_ray->player_angle) * PLAYER_SPEED;
	}
	if (last_x != c_ray->player_posx || last_y != c_ray->player_posy || last_angle != c_ray->player_angle)
	{
		minimap(c_ray);
		print_ray_struct(c_ray, 1);
	}
	last_x = c_ray->player_posx;
	last_y = c_ray->player_posy;
	last_angle = c_ray->player_angle;
	return (1);
}

int		exit_button(t_ray *c_ray)
{
	(void)c_ray;
	exit(0);
	return (1);
}
