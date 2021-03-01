/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:54:59 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/01 15:18:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	minimap(t_ray *c_ray)
{
	int	xy[2] = {0, 0};
	int	pl_xy[2] = {c_ray->player_posx, c_ray->player_posy};
	int	w_h[2] = {10, 10};
	int	w_h_m[2] = {c_ray->screen_w, c_ray->screen_h};

	draw_rectangle(c_ray, xy, w_h_m, 0x00000000);
	print_ray_struct(c_ray);
	draw_rectangle(c_ray, pl_xy, w_h, 0x00FF0000);
	mlx_put_image_to_window(c_ray->mlx_ptr, c_ray->mlx_win, c_ray->mlx_img, 0, 0);
	return (0);
}