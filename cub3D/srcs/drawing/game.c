/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:56:48 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 09:31:16 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void get_distance(t_ray *c_ray, float value, int x)
{
	float i;
	float angle;
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
	hit = 0;
	mapx = (int)c_ray->player_posx;
	mapy = (int)c_ray->player_posy;
	angle = c_ray->player_angle + value;
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
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
		if (mapx < 0 || mapy < 0 || !is_in_str("0NSEW", c_ray->c_map->map[mapy][mapx]))
			hit = 1;
	}
	i = (s_distx - d_distx) > (s_disty - d_disty) ? (s_distx - d_distx) : (s_disty - d_disty);
	int te = c_ray->screen_h / i;
	te = te / cos(c_ray->player_angle - angle);
	te = te > c_ray->screen_h ? c_ray->screen_h : te;
	draw_vertical_line(c_ray, x, te, side ? step_y > 0 ? COLOR_YELLOW : COLOR_WHITE : step_x > 0 ? COLOR_BLUE : COLOR_RED);
}

int	draw_game(t_ray *c_ray)
{
	int i;
	const int	xy[2] = {0, 0};
	const int	w_h[2] = {c_ray->screen_w, c_ray->screen_h};
	int val;

	i = -1;
	draw_rectangle(c_ray, xy, w_h, COLOR_BLACK);
	while (++i < c_ray->screen_w)
	{
		get_distance(c_ray, (PI / 4) / (c_ray->screen_w) * (i - c_ray->screen_w / 2), i);
	}
	return (0);
}