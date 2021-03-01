/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 12:55:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/01 15:17:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_entry(int key, t_ray *c_ray)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(c_ray->mlx_ptr, c_ray->mlx_win);
		exit(0);
	}
	if (key == KEY_UP_MOVE)
		c_ray->player_posy -= 10;
	if (key == KEY_DOWN_MOVE)
		c_ray->player_posy += 10;
	if (key == KEY_LEFT_MOVE)
		c_ray->player_posx -= 10;
	if (key == KEY_RIGHT_MOVE)
		c_ray->player_posx += 10;
	minimap(c_ray);
	return (1);
}

int		exit_button(t_ray *c_ray)
{
	(void)c_ray;
	exit(0);
	return (1);
}