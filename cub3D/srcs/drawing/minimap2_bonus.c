/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:38:50 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 18:39:33 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_player(t_ray *c_ray, const int xy_wh[4],
			const int color, float angle)
{
	int			i;
	int			j;
	const int	screen_height = c_ray->screen_h;
	const int	screen_width = c_ray->screen_w;
	float		a_v[4];

	i = -1;
	angle = angle + PI / 2;
	while (++i < xy_wh[3] && i + xy_wh[1] < screen_height && xy_wh[1] >= 0)
	{
		j = -1;
		while (++j < xy_wh[2] && j + xy_wh[0] < screen_width && xy_wh[0] >= 0)
		{
			if (i + j > xy_wh[2] / 2 && !(j - i + 2 > xy_wh[2] / 2))
			{
				a_v[0] = j + xy_wh[0] - xy_wh[2] / 2;
				a_v[1] = i + xy_wh[1] - xy_wh[3] / 2;
				a_v[2] = a_v[0] - xy_wh[0];
				a_v[3] = a_v[1] - xy_wh[1];
				a_v[0] = xy_wh[0] + a_v[2] * cos(angle) - a_v[3] * sin(angle);
				a_v[1] = xy_wh[1] + a_v[2] * sin(angle) + a_v[3] * cos(angle);
				draw_pixel(c_ray, a_v[0], a_v[1], color);
			}
		}
	}
}
