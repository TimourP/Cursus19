/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:54:59 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/01 19:14:58 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	int 		i;
	int 		j;
	int			xy[2];
	const int	w_h[2] = {PLAYER_SPEED, PLAYER_SPEED};
	const int	p_xy[2] = {c_ray->player_posx, c_ray->player_posy};
	const int	test[2] = {MINIMAP_WIDTH / 2, MINIMAP_HEIGHT / 2};
	const int	testbis[2] = {MINIMAP_SQUARE, MINIMAP_SQUARE};
	int mapx;
	int mapy;

	i = -1;
	while (++ i < MINIMAP_HEIGHT / PLAYER_SPEED)
	{
		j = -1;
		while (++j < MINIMAP_WIDTH / PLAYER_SPEED)
		{
			xy[0] = j * PLAYER_SPEED;
			xy[1] = i * PLAYER_SPEED;
			mapx = (p_xy[0] / PLAYER_SPEED - (c_ray->c_map->map_w * MINIMAP_SQUARE / PLAYER_SPEED / 2) + j) / (MINIMAP_SQUARE / PLAYER_SPEED) - 4;
			mapy = (p_xy[1] / PLAYER_SPEED - (c_ray->c_map->map_h * MINIMAP_SQUARE / PLAYER_SPEED / 2) + i) / (MINIMAP_SQUARE / PLAYER_SPEED) - 8;
			draw_rectangle(c_ray, xy, w_h, check_color(c_ray, mapx, mapy) ? COLOR_WHITE : COLOR_RED);
			draw_rectangle(c_ray, test, testbis, COLOR_BLACK);
		}
	}
}

void	d_map(t_ray *c_ray)
{
	int 		i;
	int 		j;
	int			xy[2];
	const int	w_h[2] = {MINIMAP_SQUARE, MINIMAP_SQUARE};

	i = -1;
	while (++ i < c_ray->c_map->map_h)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w)
		{
			xy[0] = j * MINIMAP_SQUARE;
			xy[1] = i * MINIMAP_SQUARE;
			draw_rectangle(c_ray, xy, w_h, is_in_str("0NSEW", c_ray->c_map->map[i][j]) ? COLOR_WHITE : COLOR_RED);
		}
	}
}

int	minimap(t_ray *c_ray)
{
	int	xy[2] = {0, 0};
	//int	pl_xy[2] = {c_ray->player_posx, c_ray->player_posy};
	//int	w_h[2] = {MINIMAP_PLAYER_WIDTH, 10};
	int	w_h_m[2] = {c_ray->screen_w, c_ray->screen_h};

	draw_rectangle(c_ray, xy, w_h_m, 0x00000000);
	//d_map(c_ray);
	//draw_rectangle(c_ray, pl_xy, w_h, COLOR_BLACK);
	draw_map(c_ray);
	mlx_put_image_to_window(c_ray->mlx_ptr, c_ray->mlx_win, c_ray->mlx_img, 0, 0);
	return (0);
}