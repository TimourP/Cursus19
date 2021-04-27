/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:54:59 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/27 10:56:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

const int	g_minimap_square_w_h[2] = {MINI_SQUARE, MINI_SQUARE};
const int	g_p_xy_wh[4] = {MINI_WIDTH / 2, MINI_HEIGHT
	/ 2, MINI_SQUARE, MINI_SQUARE};
const int	g_minimap_color[5] = {COLOR_MINIMAP_WALL,
	COLOR_MINIMAP_WALKABLE, COLOR_BLACK, COLOR_RED, COLOR_BLUE};

int	check_color(t_ray *c_ray, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0)
		return (2);
	if (map_x > c_ray->c_map->map_w - 1 || map_y > c_ray->c_map->map_h - 1)
		return (2);
	if (c_ray->c_map->map[map_y][map_x] == ' ')
		return (2);
	if (is_in_str("234", c_ray->c_map->map[map_y][map_x]))
		return (3);
	if (is_in_str("abc", c_ray->c_map->map[map_y][map_x]))
		return (4);
	return (is_in_str("0NSEW", c_ray->c_map->map[map_y][map_x]));
}

void	draw_player(t_ray *c_ray, const int xy_wh[4],
			const int color, float angle)
{
	int			i;
	int			j;
	const int	screen_height = c_ray->screen_h;
	const int	screen_width = c_ray->screen_w;
	float		a_v[4];

	i = -1;
	angle = angle + PI / 2;
	while (++i < xy_wh[3] && i + xy_wh[1] < screen_height && xy_wh[1] >= 0)
	{
		j = -1;
		while (++j < xy_wh[2] && j + xy_wh[0] < screen_width && xy_wh[0] >= 0)
		{
			if (i + j > xy_wh[2] / 2 && !(j - i + 2 > xy_wh[2] / 2))
			{
				a_v[0] = j + xy_wh[0] - xy_wh[2] / 2;
				a_v[1] = i + xy_wh[1] - xy_wh[3] / 2;
				a_v[2] = a_v[0] - xy_wh[0];
				a_v[3] = a_v[1] - xy_wh[1];
				a_v[0] = xy_wh[0] + a_v[2] * cos(angle) - a_v[3] * sin(angle);
				a_v[1] = xy_wh[1] + a_v[2] * sin(angle) + a_v[3] * cos(angle);
				draw_pixel(c_ray, a_v[0], a_v[1], color);
			}
		}
	}
}

void	draw_all_lines(t_ray *c_ray)
{
	int			side;
	int			line[3];
	const int	wall_color[4] = {COLOR_BLUE, COLOR_RED,
		COLOR_YELLOW, COLOR_WHITE};
	int			i;

	i = -1;
	line[0] = MINI_WIDTH / 2;
	line[1] = MINI_HEIGHT / 2;
	while (++i < c_ray->screen_w / 10)
	{
		line[2] = get_distance(c_ray, (PI / FOV) / (c_ray->screen_w)
				* (i * 10 - c_ray->screen_w / 2), &side) * MINI_SQUARE;
		draw_line(c_ray, line, c_ray->player_angle + (PI / FOV)
			/ (c_ray->screen_w) * (i * 10 - c_ray->screen_w / 2),
			wall_color[side]);
	}
}

void	draw_map(t_ray *c_ray)
{
	int			ij[2];
	int			xy[2];
	const int	pxy[2] = {c_ray->player_posx * MINI_SQUARE,
				c_ray->player_posy * MINI_SQUARE};
	int			mapx;
	int			mapy;

	ij[0] = -1;
	while (++ij[0] < MINI_HEIGHT / MINI_SQUARE)
	{
		ij[1] = -1;
		while (++ij[1] < MINI_WIDTH / MINI_SQUARE)
		{
			xy[0] = ij[1] * MINI_SQUARE - (int)((c_ray->player_posx
						- (int)c_ray->player_posx) * MINI_SQUARE);
			xy[1] = ij[0] * MINI_SQUARE - (int)((c_ray->player_posy
						- (int)c_ray->player_posy) * MINI_SQUARE);
			mapx = pxy[0] / MINI_SQUARE - MINI_WIDTH / MINI_SQUARE / 2 + ij[1];
			mapy = pxy[1] / MINI_SQUARE - MINI_HEIGHT / MINI_SQUARE / 2 + ij[0];
			draw_rectangle(c_ray, xy, g_minimap_square_w_h,
				g_minimap_color[check_color(c_ray, mapx, mapy)]);
		}
	}
	draw_all_lines(c_ray);
	draw_player(c_ray, g_p_xy_wh, COLOR_BLACK, c_ray->player_angle);
}

int	minimap(t_ray *c_ray)
{
	const int	xy_wh[4] = {0, 0, MINI_WIDTH, MINI_HEIGHT};

	draw_map(c_ray);
	draw_empty_rectangle(c_ray, xy_wh, 0x006E2C00, MINI_SQUARE);
	return (0);
}
