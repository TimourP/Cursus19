/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:47:22 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/29 11:10:42 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_life_bar(t_ray *c_ray)
{
	int						i;
	int						j;
	int						step;
	int						color;
	const t_bonus_images	*b = c_ray->bonus_images;

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
					get_pixel(b->heart_t, j / 2, i / 2, &color);
				else
					get_pixel(b->empty_heart_t, j / 2, i / 2, &color);
				if (color != 1193046)
					draw_pixel(c_ray, j + c_ray->screen_w - 380
						+ step * 35, i + 20, color);
			}
		}
	}
}

void	draw_hunger_bar(t_ray *c_ray)
{
	int						i;
	int						j;
	int						step;
	int						color;
	const t_bonus_images	*b = c_ray->bonus_images;

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
					get_pixel(b->hunger_t, j / 1.66, i / 1.66, &color);
				else
					get_pixel(b->empty_hunger_t, j / 1.66, i / 1.66, &color);
				if (color != 1193046)
					draw_pixel(c_ray, j + c_ray->screen_w
						- 380 + step * 35, i + 60, color);
			}
		}
	}
}

void	draw_center_cross(t_ray *c_ray)
{
	int	i;
	int	j;
	const int	offset_x = c_ray->screen_w / 2 - 10;
	const int	offset_y = c_ray->screen_h / 2 - 10;

	i = -1;
	while (++i < 20)
	{
		j = -1;
		while (++j < 20)
		{
			if ((i > 8 && i < 12) || (j > 8 && j < 12))
				draw_pixel(c_ray, j + offset_x, i + offset_y, COLOR_WHITE);
		}
	}
}