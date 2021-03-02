/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:54:59 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/02 10:59:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

const int	g_center_xy[2] = {MINI_WIDTH / 2, MINI_HEIGHT / 2};
const int	g_player_w_h[2] = {PLAYER_SPEED, PLAYER_SPEED};
const int	g_minimap_square_w_h[2] = {MINI_SQUARE, MINI_SQUARE};

int		check_color(t_ray *c_ray, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0)
		return (0);
	if (map_x > c_ray->c_map->map_w - 1 || map_y > c_ray->c_map->map_h - 1)
		return (0);
	return (is_in_str("0NSEW", c_ray->c_map->map[map_y][map_x]));
}

void	draw_map(t_ray *c_ray)
{
	int			ij[2];
	int			xy[2];
	const int	pxy[2] = {c_ray->player_posx, c_ray->player_posy};
	int			mapx;
	int			mapy;

	ij[0] = -1;
	while (++ij[0] < MINI_HEIGHT / MINI_SQUARE)
	{
		ij[1] = -1;
		while (++ij[1] < MINI_WIDTH / MINI_SQUARE)
		{
			xy[0] = ij[1] * MINI_SQUARE - c_ray->player_posx % MINI_SQUARE;
			xy[1] = ij[0] * MINI_SQUARE - c_ray->player_posy % MINI_SQUARE;
			mapx = pxy[0] / MINI_SQUARE - MINI_WIDTH / MINI_SQUARE / 2 + ij[1];
			mapy = pxy[1] / MINI_SQUARE - MINI_HEIGHT / MINI_SQUARE / 2 + ij[0];
			draw_rectangle(c_ray, xy, g_minimap_square_w_h,
				check_color(c_ray, mapx, mapy) ? COLOR_WHITE : COLOR_RED);
			draw_rectangle(c_ray, g_center_xy, g_player_w_h, COLOR_BLACK);
		}
	}
}

int		minimap(t_ray *c_ray)
{
	const int	xy[2] = {0, 0};
	const int	w_h[2] = {c_ray->screen_w, c_ray->screen_h};
	const int	xy_wh[4] = {0, 0, MINI_WIDTH, MINI_HEIGHT};

	draw_rectangle(c_ray, xy, w_h, COLOR_BLACK);
	draw_map(c_ray);
	draw_empty_rectangle(c_ray, xy_wh, COLOR_BLACK, MINI_SQUARE);
	mlx_put_image_to_window(c_ray->mlx_ptr, c_ray->mlx_win,
		c_ray->mlx_img, 0, 0);
	return (0);
}
