/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:55:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/02 13:57:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_next_move(t_ray *c_ray, int is_x, int value)
{
	int	next_posx;
	int	next_posy;

	next_posx = c_ray->player_posx;
	next_posy = c_ray->player_posy;
	if (is_x)
		next_posx += value;
	else
		next_posy += value;
	if (!is_in_str("0NSEW",
		c_ray->c_map->map[next_posy / MINI_SQUARE][next_posx / MINI_SQUARE]))
		return (0);
	return (1);
}

int		get_entry(int key, t_ray *c_ray)
{
	int is_change;
	const int	player_move = PLAYER_SPEED * CASE_WIDTH;

	is_change = 1;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(c_ray->mlx_ptr, c_ray->mlx_win);
		exit(0);
	}
	if (key == KEY_UP_MOVE && check_next_move(c_ray, 0, -player_move))
		c_ray->player_posy -= player_move;
	else if (key == KEY_DOWN_MOVE && check_next_move(c_ray, 0, player_move))
		c_ray->player_posy += player_move;
	else if (key == KEY_LEFT_MOVE && check_next_move(c_ray, 1, -player_move))
		c_ray->player_posx -= player_move;
	else if (key == KEY_RIGHT_MOVE && check_next_move(c_ray, 1, player_move))
		c_ray->player_posx += player_move;
	else if (key == KEY_RIGHT_ARROW)
	{
		c_ray->player_angle += 0.1;
		if (c_ray->player_angle > 2 * PI)
			c_ray->player_angle -= 2 * PI;
		c_ray->player_delx = cos(c_ray->player_angle) * PLAYER_SPEED * CASE_WIDTH;
		c_ray->player_dely = sin(c_ray->player_angle) * PLAYER_SPEED * CASE_WIDTH;
	}
	else if (key == KEY_LEFT_ARROW)
	{
		c_ray->player_angle -= 0.1;
		if (c_ray->player_angle < 0)
			c_ray->player_angle += 2 * PI;
		c_ray->player_delx = cos(c_ray->player_angle) * PLAYER_SPEED * CASE_WIDTH;
		c_ray->player_dely = sin(c_ray->player_angle) * PLAYER_SPEED * CASE_WIDTH;
	}
	else
		is_change = 0;
	if (is_change && 0)
		minimap(c_ray);
	print_ray_struct(c_ray, 1);
	return (1);
}

int		exit_button(t_ray *c_ray)
{
	(void)c_ray;
	exit(0);
	return (1);
}
