/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:47:22 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/26 14:51:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_life_bar(t_ray *c_ray)
{
	int	i;
	int	j;
	int	step;
	int	color;

	step = -1;
	while (++step < 10)
	{
		i = -1;
		while (++i < 30)
		{
			j = -1;
			while (++j < 30)
			{
				if (c_ray->player_health > step)
					get_pixel(c_ray->c_map->heart_t, j / 2, i / 2, &color);
				else
					get_pixel(c_ray->c_map->empty_heart_t,
						j / 2, i / 2, &color);
				if (color != 1193046)
					draw_pixel(c_ray, j + c_ray->screen_w - 380
						+ step * 35, i + 20, color);
			}
		}
	}
}

void	draw_hunger_bar(t_ray *c_ray)
{
	int			i;
	int			j;
	int			step;
	int			color;
	const float	v = 1.66;

	step = -1;
	while (++step < 10)
	{
		i = -1;
		while (++i < 30)
		{
			j = -1;
			while (++j < 30)
			{
				if (c_ray->player_hunger > step)
					get_pixel(c_ray->c_map->hunger_t, j / v, i / v, &color);
				else
					get_pixel(c_ray->c_map->empty_hunger_t, j / v, i / v, &color);
				if (color != 1193046)
					draw_pixel(c_ray, j + c_ray->screen_w - 380 + step * 35, i + 60, color);
			}
		}
	}
}
