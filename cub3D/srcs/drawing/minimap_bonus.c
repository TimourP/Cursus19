/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:54:59 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/12 12:21:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

const int	g_minimap_square_w_h[2] = {MINI_SQUARE, MINI_SQUARE};
const int	g_p_xy_wh[4] = {MINI_WIDTH / 2, MINI_HEIGHT
	/ 2, MINI_SQUARE, MINI_SQUARE};
const int	g_minimap_color[5] = {COLOR_MINIMAP_WALL,
	COLOR_MINIMAP_WALKABLE, COLOR_BLACK, COLOR_RED, COLOR_BLUE};

static int	check_color(t_ray *c_ray, int map_x, int map_y)
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

static void	draw_monsters(t_ray *c_ray, int mapx, int mapy, int xy[2])
{
	t_monster_list	*lst;

	lst = c_ray->monster_list;
	while (lst)
	{
		if ((int)lst->content->x == mapx && (int)lst->content->y == mapy)
			draw_rectangle(c_ray, xy, g_minimap_square_w_h, COLOR_MONSTERS);
		lst = lst->next;
	}
}

static void	draw_all_lines(t_ray *c_ray)
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
	draw_player(c_ray, g_p_xy_wh, COLOR_BLACK, c_ray->player_angle);
}

static void	draw_map(t_ray *c_ray)
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
			draw_monsters(c_ray, mapx, mapy, xy);
		}
	}
	draw_all_lines(c_ray);
}

int	minimap(t_ray *c_ray)
{
	const int	xy_wh[4] = {0, 0, MINI_WIDTH, MINI_HEIGHT};

	draw_map(c_ray);
	draw_empty_rectangle(c_ray, xy_wh, 0x006E2C00, MINI_SQUARE);
	return (0);
}
