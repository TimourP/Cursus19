/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:56:48 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/19 12:27:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	g_wall_color[4] = {COLOR_BLUE, COLOR_RED, COLOR_YELLOW, COLOR_WHITE};

float	get_texture_value(t_ray *c_ray, t_ray_calc *calc)
{
	float	angle;
	float	text_value;

	if (get_side(calc) == 0)
	{
		angle = calc->angle + PI / 2;
		text_value = sin(angle) * calc->final_dist
			+ c_ray->player_posx - (int)c_ray->player_posx;
		text_value -= (int)text_value;
		if (text_value < 0)
			text_value = fabs(1 + text_value);
	}
	else if (get_side(calc) == 1)
	{
		angle = calc->angle;
		text_value = sin(angle) * calc->final_dist
			+ (c_ray->player_posy - (int)c_ray->player_posy);
		if (text_value < 0)
			text_value = 1.0 - fabs(text_value - (int)text_value);
		else
			text_value = fabs(text_value - (int)text_value);
	}
	else if (get_side(calc) == 2)
	{
		angle = calc->angle - PI / 2;
		text_value = sin(angle) * calc->final_dist
			- (c_ray->player_posx - (int)c_ray->player_posx);
		if (text_value < 0)
			text_value = 1 - fabs(text_value - (int)text_value);
		else
			text_value = fabs(text_value - (int)text_value);
	}
	else if (get_side(calc) == 3)
	{
		angle = calc->angle + PI;
		text_value = sin(angle) * calc->final_dist
			- (c_ray->player_posy - (int)c_ray->player_posy);
		if (text_value < 0)
			text_value = 1 - fabs(text_value - (int)text_value);
		else
			text_value = fabs(text_value - (int)text_value);
	}
	return (text_value);
}

int	draw_game(t_ray *c_ray)
{
	int			i_v[2];
	const int	xy[2] = {0, 0};
	const int	w_h[2] = {c_ray->screen_w, c_ray->screen_h};
	int			side;
	float		y_value;

	i_v[0] = -1;
	ft_sprclear(&c_ray->start_list);
	c_ray->start_list = NULL;
	draw_rectangle(c_ray, xy, w_h, COLOR_BLACK);
	if (BONUS)
		draw_sky(c_ray);
	while (++i_v[0] < c_ray->screen_w)
	{
		side = i_v[0];
		i_v[1] = get_line_height(c_ray, (PI / FOV) / (c_ray->screen_w)
				* (i_v[0] - c_ray->screen_w / 2), &side, &y_value);
		if (!LIGHT && side == 0)
			draw_vertical_texture(c_ray, i_v, c_ray->c_map->north_t, y_value);
		else if (!LIGHT && side == 1)
			draw_vertical_texture(c_ray, i_v, c_ray->c_map->east_t, y_value);
		else if (!LIGHT && side == 2)
			draw_vertical_texture(c_ray, i_v, c_ray->c_map->south_t, y_value);
		else if (!LIGHT && side == 3)
			draw_vertical_texture(c_ray, i_v, c_ray->c_map->west_t, y_value);
		else
			draw_vertical_line(c_ray, i_v[0], i_v[1],
				g_wall_color[side]);
	}
	draw_sprite(c_ray, c_ray->start_list);
	return (0);
}
