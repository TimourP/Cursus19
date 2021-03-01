/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:32:33 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/01 15:06:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_ray *c_ray)
{
	c_ray->player_posx = 200;
	c_ray->player_posy = 200;
}

int		init_raycasting(t_ray *c_ray, t_map *c_map)
{
	init_player(c_ray);
	c_ray->c_map = c_map;
	c_ray->screen_h = c_map->screen_h;
	c_ray->screen_w = c_map->screen_w;
	c_ray->mlx_ptr = mlx_init();
	c_ray->mlx_win = mlx_new_window(c_ray->mlx_ptr, c_map->screen_w, c_map->screen_h, "CUB3D");
	c_ray->mlx_img = mlx_new_image(c_ray->mlx_ptr, c_map->screen_w, c_map->screen_h);
	c_ray->img_addr = mlx_get_data_addr(c_ray->mlx_img, &c_ray->img_bpp,
						&c_ray->img_line_l, &c_ray->img_edian);
	print_ray_struct(c_ray);
	mlx_hook(c_ray->mlx_win, KEY_PRESS_EVENT, 1L<<0, get_entry, c_ray);
	mlx_hook(c_ray->mlx_win, CROSS_BTN_EVENT, 1L<<17, exit_button, c_ray);
	return (1);
}
