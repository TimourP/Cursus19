/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:39:26 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 18:37:24 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	red_color(int color, int red_value)
{
	const int	current_red_value = (int)(((color & 0x00FF0000) >> 16));
	int			new_value;

	new_value = current_red_value + red_value * 50;
	if (new_value > 255)
		new_value = 255;
	return (((new_value) << 16)
		| (int)(((color & 0x0000FF00)))
		| (int)((color & 0x000000FF)));
}

static int	shadow(int color, double props)
{
	if (props < 0)
		props = 0;
	else if (props > 1)
		props = 1;
	return (((int)(((color & 0x00FF0000) >> 16) * props) << 16)
			| ((int)(((color & 0x0000FF00) >> 8) * props) << 8)
			| ((int)((color & 0x000000FF) * props)));
}

void	draw_vertical_texture(t_ray *c_ray, int x_len[2],
	t_image *texture, float y_value)
{
	int			i;
	const float	texture_ratio = (float)x_len[1] / texture->height;
	int			color;
	const int	offset = (c_ray->screen_h - x_len[1]) / 2
		+ (c_ray->look_offset);
	const int	texture_x = texture->width * y_value;

	i = -1;
	if (offset < 0)
		i = -offset;
	while (++i < x_len[1] && i + offset < c_ray->screen_h)
	{
		get_pixel(texture, texture_x, i / texture_ratio, &color);
		color = shadow(color, (15 - c_ray->all_distances[x_len[0]]) / 15);
		if (i + offset >= 0)
			draw_pixel(c_ray, x_len[0], i + offset, color);
	}
	i--;
	while (++i + offset < c_ray->screen_h)
	{
		color = shadow(c_ray->c_map->floor_t, 1 - (float)(c_ray->screen_h - i
					- offset + c_ray -> look_offset) / c_ray->screen_h * 2.2);
		if (i + offset >= 0)
			draw_pixel(c_ray, x_len[0], i + offset, color);
	}
}

void	draw_sprite_loop(t_ray *c_ray, t_sprite_list *c_list,
		int i_j[2], float ratio)
{
	int	color;

	get_pixel(c_list->content->img, (i_j[1] - c_list->content->start_x
			+ c_list->content->offset_x) / ratio, (i_j[0]
			- c_list->content->start_y + c_list->content->offset_y)
		/ ratio, &color);
	if (color != 1193046 && c_list->content->distance
		< c_ray->all_distances[i_j[1]])
	{
		color = shadow(red_color(color, c_list->content->shot_count),
				(15 - c_list->content->distance) / 15);
		draw_pixel(c_ray, i_j[1], i_j[0], color);
	}
}

void	draw_sprite(t_ray *c_ray, t_sprite_list *c_list)
{
	int		i_j[2];
	int		color;
	float	ratio;

	while (c_list)
	{
		ratio = (float)c_list->content->height / c_list->content->img->height;
		i_j[0] = c_list->content->start_y - 1;
		while (++i_j[0] < c_list->content->end_y)
		{
			i_j[1] = c_list->content->start_x - 1;
			while (++i_j[1] < c_list->content->end_x)
				draw_sprite_loop(c_ray, c_list, i_j, ratio);
		}
		c_list = c_list->next;
	}
}
