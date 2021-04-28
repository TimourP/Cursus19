/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:26:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/28 20:12:31 by tpetit           ###   ########.fr       */
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
		if (calc->mapx < 0 || calc->mapy < 0
			|| !is_in_str("0234abcNSEWM", c_ray->c_map->map[calc->mapy][calc->mapx]))
			calc->hit = 1;
	}
}
