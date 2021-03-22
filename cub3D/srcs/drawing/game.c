/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:56:48 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/22 20:17:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	draw_game(t_ray *c_ray)
{
	int i;
	const int	xy[2] = {0, 0};
	const int	w_h[2] = {c_ray->screen_w, c_ray->screen_h};

	i = -1;
	draw_rectangle(c_ray, xy, w_h, COLOR_BLACK);
	while (++i < c_ray->screen_w)
	{
		draw_vertical_line(c_ray, i, 720, COLOR_RED);
	}
	return (0);
}