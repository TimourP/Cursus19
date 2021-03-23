/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:56:48 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 11:55:30 by tpetit           ###   ########.fr       */
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

int	get_line_height(t_ray *c_ray, float value, int *side)
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
	calc.line_height = c_ray->screen_h / calc.final_dist;
	calc.line_height = calc.line_height / cos(c_ray->player_angle - calc.angle);
	if (calc.line_height > c_ray->screen_h)
		calc.line_height = c_ray->screen_h;
	return (calc.line_height);
}

int	draw_game(t_ray *c_ray)
{
	int			i;
	const int	xy[2] = {0, 0};
	const int	w_h[2] = {c_ray->screen_w, c_ray->screen_h};
	int			side;
	int			value;

	i = -1;
	draw_rectangle(c_ray, xy, w_h, COLOR_BLACK);
	while (++i < c_ray->screen_w)
	{
		value = get_line_height(c_ray, (PI / 4) / (c_ray->screen_w)
				* (i - c_ray->screen_w / 2), &side);
		draw_vertical_line(c_ray, i, value, g_wall_color[side]);
	}
	return (0);
}
