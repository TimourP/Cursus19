/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:24:06 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/19 12:05:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_sky(t_ray *c_ray)
{
	int	i;
	int	j;
	int	color;
	int	offset;

	i = -1;
	offset = c_ray->player_angle / (2 * PI) * c_ray->sky->width;
	while (++i < c_ray->screen_w)
	{
		j = -1;
		while (++j < c_ray->screen_h)
		{
			get_pixel(c_ray->sky, (i + offset) % c_ray->sky->width,
				abs(j - c_ray->look_offset) % c_ray->sky->height, &color);
			draw_pixel(c_ray, i, j, color);
		}
	}
}
