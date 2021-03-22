/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:54:59 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/22 19:20:57 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

const int	g_minimap_square_w_h[2] = {MINI_SQUARE, MINI_SQUARE};
const int	g_p_xy_wh[4] = {MINI_WIDTH / 2, MINI_HEIGHT
	/ 2, MINI_SQUARE, MINI_SQUARE};

int		check_color(t_ray *c_ray, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0)
		return (0);
	if (map_x > c_ray->c_map->map_w - 1 || map_y > c_ray->c_map->map_h - 1)
		return (0);
	return (is_in_str("0NSEW", c_ray->c_map->map[map_y][map_x]));
}

float	div_zero(float number1, float number2)
{
	if (number2 == 0)
		return(1);
	else
		return (number1 / number2);
}

void drawRay(t_ray *c_ray)
{
	float i;
	float angle;
	int	line_values[3] = {MINI_WIDTH / 2, MINI_HEIGHT / 2, 0};
	float d_disty;
	float d_distx;
	float s_disty;
	float s_distx;
	int step_x;
	int step_y;
	int hit;
	int mapx;
	int mapy;
	int side;
	//line_values[2] = (1 - d_x) * div_zero(MINI_SQUARE, cos(angle));
	hit = 0;
	mapx = (int)c_ray->player_posx;
	mapy = (int)c_ray->player_posy;
	angle = c_ray->player_angle;
	d_distx = fabs(div_zero(1, cos(angle)));
	d_disty = fabs(div_zero(1, cos(PI / 2 - angle)));
	if (angle > 3 * PI / 2 || angle < PI / 2)
	{
		step_x = 1;
		s_distx = (mapx + 1 - c_ray->player_posx) * d_distx;
	}
	else
	{
		step_x = -1;
		s_distx = (c_ray->player_posx - mapx) * d_distx;
	}
	if (angle < PI)
	{
		step_y = 1;
		s_disty = (mapy + 1 - c_ray->player_posy) * d_disty;
	}
	else
	{
		step_y = -1;
		s_disty = (c_ray->player_posy - mapy) * d_disty;
	}
	hit = 0;
	while (hit == 0)
	{
		if (s_distx < s_disty)
		{
			s_distx += d_distx;
			mapx += step_x;
			side = 0;
		}
		else
		{
			s_disty += d_disty;
			mapy += step_y;
			side = 1;
		}
		if (c_ray->c_map->map[mapy][mapx] != 0)
		{
			hit = 1;
			printf("%d %d\n", mapx, mapy);
		}
	}
	
	printf("%f %f\n", s_distx, s_distx);
	line_values[2] = s_disty > s_distx ? s_distx * MINI_SQUARE : s_disty * MINI_SQUARE;
	draw_line(c_ray, line_values, angle, COLOR_RED);
}

void	draw_map(t_ray *c_ray)
{
	int			ij[2];
	int			xy[2];
	const int	pxy[2] = {c_ray->player_posx * MINI_SQUARE, c_ray->player_posy * MINI_SQUARE};
	int			mapx;
	int			mapy;

	ij[0] = -1;
	while (++ij[0] < MINI_HEIGHT / MINI_SQUARE)
	{
		ij[1] = -1;
		while (++ij[1] < MINI_WIDTH / MINI_SQUARE)
		{
			xy[0] = ij[1] * MINI_SQUARE - (int)((c_ray->player_posx - (int)c_ray->player_posx) * MINI_SQUARE);
			xy[1] = ij[0] * MINI_SQUARE - (int)((c_ray->player_posy - (int)c_ray->player_posy) * MINI_SQUARE);
			mapx = pxy[0] / MINI_SQUARE - MINI_WIDTH / MINI_SQUARE / 2 + ij[1];
			mapy = pxy[1] / MINI_SQUARE - MINI_HEIGHT / MINI_SQUARE / 2 + ij[0];
			draw_rectangle(c_ray, xy, g_minimap_square_w_h, check_color(c_ray,
					mapx, mapy) ? COLOR_MINIMAP_WALKABLE : COLOR_MINIMAP_WALL);
		}
	}
	draw_player(c_ray, g_p_xy_wh, COLOR_BLACK, c_ray->player_angle);
	drawRay(c_ray);
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
