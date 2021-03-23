/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:32:33 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 12:23:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_ray *c_ray)
{
	int	i;
	int	j;

	i = -1;
	c_ray->player_angle = 0;
	c_ray->player_delx = sin(c_ray->player_angle) * PLAYER_SPEED;
	c_ray->player_dely = cos(c_ray->player_angle) * PLAYER_SPEED;
	while (++i < c_ray->c_map->map_h + 1)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w + i)
		{
			if (is_in_str("NSEW", c_ray->c_map->map[i][j]))
			{
				c_ray->player_posx = j + 0.5;
				c_ray->player_posy = i + 0.5;
				return ;
			}
		}
	}
}

void	init_moves(t_ray *c_ray)
{
	c_ray->go_backward = 0;
	c_ray->go_forward = 0;
	c_ray->go_left = 0;
	c_ray->go_right = 0;
	c_ray->turn_left = 0;
	c_ray->turn_right = 0;
	c_ray->look_offset = 0;
	c_ray->look_up = 0;
	c_ray->look_down = 0;
}

int	init_raycasting(t_ray *c_ray, t_map *c_map)
{
	c_ray->c_map = c_map;
	init_moves(c_ray);
	init_player(c_ray);
	c_ray->screen_h = c_map->screen_h;
	c_ray->screen_w = c_map->screen_w;
	c_ray->mlx_ptr = mlx_init();
	c_ray->mlx_win = mlx_new_window(c_ray->mlx_ptr,
			c_map->screen_w, c_map->screen_h, "CUB3D");
	c_ray->mlx_img = mlx_new_image(c_ray->mlx_ptr,
			c_map->screen_w, c_map->screen_h);
	c_ray->img_addr = mlx_get_data_addr(c_ray->mlx_img, &c_ray->img_bpp,
			&c_ray->img_line_l, &c_ray->img_edian);
	mlx_hook(c_ray->mlx_win, KEY_PRESS_EVENT, 1L << 0, key_press, c_ray);
	mlx_hook(c_ray->mlx_win, KEY_RELEASE_EVENT, 1L << 1, key_release, c_ray);
	mlx_hook(c_ray->mlx_win, CROSS_BTN_EVENT, 1L << 17, exit_button, c_ray);
	mlx_loop_hook(c_ray->mlx_ptr, get_next_frame, c_ray);
	return (1);
}
