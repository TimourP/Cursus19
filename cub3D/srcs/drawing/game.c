/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:56:48 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/19 11:33:30 by tpetit           ###   ########.fr       */
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

static int	is_in_list(t_sprite_list *c_list, int mapx, int mapy, t_sprite_list **current)
{
	while (c_list)
	{
		if (c_list->content->map_x == mapx && c_list->content->map_y == mapy)
		{
			*current = c_list;
			return (1);
		}
		c_list = c_list->next;
	}
	return (0);
}

static void	set_sprite(t_ray *c_ray, t_ray_calc *calc)
{
	t_sprite_list	*new_elem;
	t_sprite_list	*current;
	t_sprite		*new_sprite;

	if (!is_in_list(c_ray->start_list, calc->mapx, calc->mapy, &current))
	{
		new_sprite = malloc(sizeof(t_sprite));
		new_sprite->map_x = calc->mapx;
		new_sprite->map_y = calc->mapy;
		new_sprite->distance = sqrt(pow((calc->mapx + 0.5 - c_ray->player_posx), 2) + pow((calc->mapy + 0.5 - c_ray->player_posy), 2)) - 0.5;
		new_sprite->start_x = calc->x;
		new_elem = ft_sprnew(new_sprite);
		ft_spradd_back(&(c_ray->start_list), new_elem);
	} else {
		new_sprite->end_x = calc->x;
	}
}

static void	set_hit(t_ray *c_ray, t_ray_calc *calc, int params)
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
		if (params && (calc->mapx < 0 || calc->mapy < 0
			|| is_in_str("2", c_ray->c_map->map[calc->mapy][calc->mapx])))
			set_sprite(c_ray, calc);
		if (calc->mapx < 0 || calc->mapy < 0
			|| !is_in_str("02NSEW", c_ray->c_map->map[calc->mapy][calc->mapx]))
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
	calc.x = *side;
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
	set_hit(c_ray, &calc, 1);
	*side = get_side(&calc);
	calc.final_dist = calc.s_disty - calc.d_disty;
	if (calc.final_dist < calc.s_distx - calc.d_distx)
		calc.final_dist = calc.s_distx - calc.d_distx;
	if (!LIGHT)
		*text_value = get_texture_value(c_ray, &calc);
	calc.line_height = c_ray->screen_h / calc.final_dist * 1.2;
	calc.line_height = calc.line_height / cos(calc.angle - c_ray->player_angle);
	if (calc.line_height > c_ray->screen_h * 3)
		calc.line_height = c_ray->screen_h * 3;
	return (calc.line_height);
}

float	get_distance(t_ray *c_ray, float value, int *side)
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
	set_hit(c_ray, &calc, 0);
	*side = get_side(&calc);
	calc.final_dist = calc.s_disty - calc.d_disty;
	if (calc.final_dist < calc.s_distx - calc.d_distx)
		calc.final_dist = calc.s_distx - calc.d_distx;
	return (calc.final_dist);
}

float	get_absolute_distance(t_ray *c_ray, float angle)
{
	t_ray_calc	calc;

	calc.hit = 0;
	calc.mapx = (int)c_ray->player_posx;
	calc.mapy = (int)c_ray->player_posy;
	calc.angle = angle;
	if (calc.angle < 0)
		calc.angle += 2 * PI;
	if (calc.angle > 2 * PI)
		calc.angle -= 2 * PI;
	calc.d_distx = fabs(div_zero(1, cos(calc.angle)));
	calc.d_disty = fabs(div_zero(1, cos(PI / 2 - calc.angle)));
	set_steps(c_ray, &calc);
	set_hit(c_ray, &calc, 0);
	calc.final_dist = calc.s_disty - calc.d_disty;
	if (calc.final_dist < calc.s_distx - calc.d_distx)
		calc.final_dist = calc.s_distx - calc.d_distx;
	return (calc.final_dist);
}

int	draw_game(t_ray *c_ray)
{
	int			i_value[2];
	const int	xy[2] = {0, 0};
	const int	w_h[2] = {c_ray->screen_w, c_ray->screen_h};
	int			side;
	float		y_value;

	i_value[0] = -1;
	ft_sprclear(&c_ray->start_list);
	c_ray->start_list = NULL;
	draw_rectangle(c_ray, xy, w_h, COLOR_BLACK);
	if (BONUS)
		draw_sky(c_ray);
	while (++i_value[0] < c_ray->screen_w)
	{
		side = i_value[0];
		i_value[1] = get_line_height(c_ray, (PI / FOV) / (c_ray->screen_w)
				* (i_value[0] - c_ray->screen_w / 2), &side, &y_value);
		if (!LIGHT && side == 0)
			draw_vertical_texture(c_ray, i_value, c_ray->c_map->north_t, y_value);
		else if (!LIGHT && side == 1)
			draw_vertical_texture(c_ray, i_value, c_ray->c_map->east_t, y_value);
		else if (!LIGHT && side == 2)
			draw_vertical_texture(c_ray, i_value, c_ray->c_map->south_t, y_value);
		else if (!LIGHT && side == 3)
			draw_vertical_texture(c_ray, i_value, c_ray->c_map->west_t, y_value);
		else
			draw_vertical_line(c_ray, i_value[0], i_value[1],
				g_wall_color[side]);
	}
	draw_sprite(c_ray, c_ray->start_list);
	return (0);
}
