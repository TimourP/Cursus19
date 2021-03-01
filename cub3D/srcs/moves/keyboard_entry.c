/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:55:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/01 20:06:41 by tpetit           ###   ########.fr       */
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
	if (!is_in_str("0NSEW", c_ray->c_map->map[next_posy / PLAYER_SPEED][next_posx / PLAYER_SPEED]))
		return(0);
	return (1);
}

int		get_entry(int key, t_ray *c_ray)
{
	int is_change;

	is_change = 1;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(c_ray->mlx_ptr, c_ray->mlx_win);
		exit(0);
	}
	if (key == KEY_UP_MOVE && check_next_move(c_ray, 0, -PLAYER_SPEED))
		c_ray->player_posy -= PLAYER_SPEED;
	else if (key == KEY_DOWN_MOVE && check_next_move(c_ray, 0, PLAYER_SPEED))
		c_ray->player_posy += PLAYER_SPEED;
	else if (key == KEY_LEFT_MOVE && check_next_move(c_ray, 1, -PLAYER_SPEED))
		c_ray->player_posx -= PLAYER_SPEED;
	else if (key == KEY_RIGHT_MOVE && check_next_move(c_ray, 1, PLAYER_SPEED))
		c_ray->player_posx += PLAYER_SPEED;
	else
		is_change = 0;
	if (is_change)
		minimap(c_ray);
	return (1);
}

int		exit_button(t_ray *c_ray)
{
	(void)c_ray;
	exit(0);
	return (1);
}