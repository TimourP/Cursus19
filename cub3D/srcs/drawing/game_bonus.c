/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:52:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/29 13:51:56 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	g_wall_color[4] = {COLOR_BLUE, COLOR_RED, COLOR_YELLOW, COLOR_WHITE};

static float	get_texture_value_end(t_ray *c_ray, t_ray_calc *calc)
{
	float	angle;
	float	text_value;

	if (get_side(calc) == 2)
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
	else
		return (get_texture_value_end(c_ray, calc));
	return (text_value);
}

static t_image	*text_side(t_ray *c_ray, int side)
{
	if (side == 0)
		return (c_ray->c_map->north_t);
	else if (side == 1)
		return (c_ray->c_map->east_t);
	else if (side == 2)
		return (c_ray->c_map->south_t);
	else
		return (c_ray->c_map->west_t);
}

void	get_shot(t_ray *c_ray, t_sprite_list *s_lst, t_monster_list *m_lst)
{
	int	id;
	t_sprite *elem;
	const int	x = c_ray->screen_w / 2;
	const int	y = c_ray->screen_h / 2;

	c_ray->shoot = 0;
	id = -1;
	system("afplay sounds/gun_shot.mp3 &>/dev/null &");
	while (s_lst)
	{
		if(s_lst->content->id != -1)
		{
			elem = s_lst->content;
			if (elem->start_x < x && elem->end_x > x && elem->start_y < y && elem->end_y > y && c_ray->all_distances[x] > elem->distance)
				id = elem->id;
		}
		s_lst = s_lst->next;
	}
	while (m_lst)
	{
		if (id != -1 && m_lst->content->id == id)
		{
			m_lst->content->shot_count = m_lst->content->shot_count + 1;
			if (m_lst->content->shot_count > 4)
			{
				m_lst->content->x = 0;
				m_lst->content->y = 0;
				m_lst->content->shot_count = 0;
			}
		}
		m_lst = m_lst->next;
	}
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
	draw_rectangle(c_ray, xy, w_h, COLOR_BLACK);
	get_all_sprites(c_ray);
	draw_sky(c_ray);
	while (++i_v[0] < c_ray->screen_w)
	{
		side = i_v[0];
		i_v[1] = get_line_height(c_ray, (PI / FOV) / (c_ray->screen_w)
				* (i_v[0] - c_ray->screen_w / 2), &side, &y_value);
		if (!LIGHT)
			draw_vertical_texture(c_ray, i_v, text_side(c_ray, side), y_value);
		else
			draw_vertical_line(c_ray, i_v[0], i_v[1],
				g_wall_color[side]);
	}
	draw_sprite(c_ray, c_ray->start_list);
	if (c_ray->shoot)
		get_shot(c_ray, c_ray->start_list, c_ray->monster_list);
	return (0);
}
