/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:12:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 20:13:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_images(t_map *c_map)
{
	if (!c_map->north_t->mlx_img || !c_map->south_t->mlx_img
		|| !c_map->west_t->mlx_img || !c_map->east_t->mlx_img
		|| !c_map->sprite_t->mlx_img)
		return (free_on_error(c_map, FILE_ERROR));
	return (1);
}

static int	get_sprites_images(t_ray *c_ray, t_map *c_map)
{
	c_map->sprite_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->sprite_t->path, &c_map->sprite_t->width,
			&c_map->sprite_t->height);
	if (c_map->sprite_t->mlx_img)
	{
		c_map->sprite_t->addr = mlx_get_data_addr(c_map->sprite_t->mlx_img,
				&c_map->sprite_t->bpp, &c_map->sprite_t->line_l,
				&c_map->sprite_t->edian);
	}
	return (check_images(c_map));
}

static int	get_images_end(t_ray *c_ray, t_map *c_map)
{
	c_map->west_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->west_t->path, &c_map->west_t->width,
			&c_map->west_t->height);
	if (c_map->west_t->mlx_img)
	{
		c_map->west_t->addr = mlx_get_data_addr(c_map->west_t->mlx_img,
				&c_map->west_t->bpp, &c_map->west_t->line_l,
				&c_map->west_t->edian);
	}
	c_map->south_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->south_t->path, &c_map->south_t->width,
			&c_map->south_t->height);
	if (c_map->south_t->mlx_img)
	{
		c_map->south_t->addr = mlx_get_data_addr(c_map->south_t->mlx_img,
				&c_map->south_t->bpp, &c_map->south_t->line_l,
				&c_map->south_t->edian);
	}
	return (get_sprites_images(c_ray, c_map));
}

int	get_images(t_ray *c_ray, t_map *c_map)
{
	c_map->north_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->north_t->path, &c_map->north_t->width,
			&c_map->north_t->height);
	if (c_map->north_t->mlx_img)
	{
		c_map->north_t->addr = mlx_get_data_addr(c_map->north_t->mlx_img,
				&c_map->north_t->bpp, &c_map->north_t->line_l,
				&c_map->north_t->edian);
	}
	c_map->east_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->east_t->path, &c_map->east_t->width,
			&c_map->east_t->height);
	if (c_map->east_t->mlx_img)
	{
		c_map->east_t->addr = mlx_get_data_addr(c_map->east_t->mlx_img,
				&c_map->east_t->bpp, &c_map->east_t->line_l,
				&c_map->east_t->edian);
	}
	return (get_images_end(c_ray, c_map));
}
