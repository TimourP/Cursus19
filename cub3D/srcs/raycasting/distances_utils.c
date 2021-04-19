/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:26:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/19 17:24:58 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_side(t_ray_calc *calc)
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

void	set_steps(t_ray *c_ray, t_ray_calc *calc)
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

static int	is_in_list(t_sprite_list *c_list, int mapx,
			int mapy, t_sprite_list **current)
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
		new_sprite->distance = sqrt(pow((calc->mapx + 0.5
						- c_ray->player_posx), 2) + pow((calc->mapy + 0.5
						- c_ray->player_posy), 2)) - 0.5;
		new_sprite->start_x = calc->x;
		new_elem = ft_sprnew(new_sprite);
		ft_spradd_back(&c_ray->start_list, new_elem);
	}
	else
	{
		new_sprite->end_x = calc->x;
	}
}

void	set_hit(t_ray *c_ray, t_ray_calc *calc, int params)
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
