/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:56:48 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/24 18:33:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	g_wall_color[4] = {COLOR_BLUE, COLOR_RED, COLOR_YELLOW, COLOR_WHITE};

static int	get_side(t_ray_calc *calc)
{
	if (calc->side == 0)
	{
		if (calc->step_x > 0)
			return (1);
		return (3);
	}
	if (calc->step_y > 0)
		return (2);
	return (0);
}

static void	set_steps(t_ray *c_ray, t_ray_calc *calc)
{
	if (calc->angle > 3 * PI / 2 || calc->angle < PI / 2)
	{
		calc->step_x = 1;
		calc->s_distx = (calc->mapx + 1 - c_ray->player_posx) * calc->d_distx;
	}
	else
	{
		calc->step_x = -1;
		calc->s_distx = (c_ray->player_posx - calc->mapx) * calc->d_distx;
	}
	if (calc->angle < PI)
	{
		calc->step_y = 1;
		calc->s_disty = (calc->mapy + 1 - c_ray->player_posy) * calc->d_disty;
	}
	else
	{
		calc->step_y = -1;
		calc->s_disty = (c_ray->player_posy - calc->mapy) * calc->d_disty;
	}
}

static void	set_hit(t_ray *c_ray, t_ray_calc *calc)
{
	calc->hit = 0;
	while (calc->hit == 0)
	{
		if (calc->s_distx < calc->s_disty)
		{
			calc->s_distx += calc->d_distx;
			calc->mapx += calc->step_x;
			calc->side = 0;
		}
		else
		{
			calc->s_disty += calc->d_disty;
			calc->mapy += calc->step_y;
			calc->side = 1;
		}
		if (calc->mapx < 0 || calc->mapy < 0
			|| !is_in_str("0NSEW", c_ray->c_map->map[calc->mapy][calc->mapx]))
			calc->hit = 1;
	}
}

static float	get_texture_value(t_ray *c_ray, t_ray_calc *calc)
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

int	get_line_height(t_ray *c_ray, float value, int *side, float *text_value)
{
	t_ray_calc	calc;

	calc.hit = 0;
	calc.mapx = (int)c_ray->player_posx;
	calc.mapy = (int)c_ray->player_posy;
	calc.angle = c_ray->player_angle + value;
	if (calc.angle < 0)
		calc.angle += 2 * PI;
	if (calc.angle > 2 * PI)
		calc.angle -= 2 * PI;
	calc.d_distx = fabs(div_zero(1, cos(calc.angle)));
	calc.d_disty = fabs(div_zero(1, cos(PI / 2 - calc.angle)));
	set_steps(c_ray, &calc);
	set_hit(c_ray, &calc);
	*side = get_side(&calc);
	calc.final_dist = calc.s_disty - calc.d_disty;
	if (calc.final_dist < calc.s_distx - calc.d_distx)
		calc.final_dist = calc.s_distx - calc.d_distx;
	*text_value = get_texture_value(c_ray, &calc);
	calc.line_height = c_ray->screen_h / calc.final_dist * 1.2;
	calc.line_height = calc.line_height / cos(c_ray->player_angle - calc.angle);
	if (calc.line_height > c_ray->screen_h * 3)
		calc.line_height = c_ray->screen_h * 3;
	return (calc.line_height);
}

int	get_distance(t_ray *c_ray, float value, int *side)
{
	t_ray_calc	calc;

	calc.hit = 0;
	calc.mapx = (int)c_ray->player_posx;
	calc.mapy = (int)c_ray->player_posy;
	calc.angle = c_ray->player_angle + value;
	if (calc.angle < 0)
		calc.angle += 2 * PI;
	if (calc.angle > 2 * PI)
		calc.angle -= 2 * PI;
	calc.d_distx = fabs(div_zero(1, cos(calc.angle)));
	calc.d_disty = fabs(div_zero(1, cos(PI / 2 - calc.angle)));
	set_steps(c_ray, &calc);
	set_hit(c_ray, &calc);
	*side = get_side(&calc);
	calc.final_dist = calc.s_disty - calc.d_disty;
	if (calc.final_dist < calc.s_distx - calc.d_distx)
		calc.final_dist = calc.s_distx - calc.d_distx;
	return (calc.final_dist * MINI_SQUARE);
}

int	draw_game(t_ray *c_ray)
{
	int			i_value[2];
	const int	xy[2] = {0, 0};
	const int	w_h[2] = {c_ray->screen_w, c_ray->screen_h};
	int			side;
	float		y_value;

	i_value[0] = -1;
	draw_rectangle(c_ray, xy, w_h, COLOR_BLACK);
	draw_sky(c_ray);
	while (++i_value[0] < c_ray->screen_w)
	{
		i_value[1] = get_line_height(c_ray, (PI / FOV) / (c_ray->screen_w)
				* (i_value[0] - c_ray->screen_w / 2), &side, &y_value);
		if (side == 0)
			draw_vertical_texture(c_ray, i_value, c_ray->c_map->north_t, y_value);
		else if (side == 1)
			draw_vertical_texture(c_ray, i_value, c_ray->c_map->east_t, y_value);
		else if (side == 2)
			draw_vertical_texture(c_ray, i_value, c_ray->c_map->south_t, y_value);
		else if (side == 3)
			draw_vertical_texture(c_ray, i_value, c_ray->c_map->west_t, y_value);
		else
			draw_vertical_line(c_ray, i_value[0], i_value[1],
				g_wall_color[side]);
	}
	return (0);
}
