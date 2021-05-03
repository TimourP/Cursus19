/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:45:34 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/03 16:31:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	get_hud_images_end(t_ray *c_ray, t_map *c_map)
{
	t_bonus_images	*bon;

	bon = c_ray->bonus_images;
	bon->empty_heart_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/empty_heart.xpm", &bon->empty_heart_t->width,
			&bon->empty_heart_t->height);
	if (bon->empty_heart_t->mlx_img)
	{
		bon->empty_heart_t->addr
			= mlx_get_data_addr(bon->empty_heart_t->mlx_img,
				&bon->empty_heart_t->bpp, &bon->empty_heart_t->line_l,
				&bon->empty_heart_t->edian);
	}
	bon->empty_hunger_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/empty_hunger.xpm", &bon->empty_hunger_t->width,
			&bon->empty_hunger_t->height);
	if (bon->empty_hunger_t->mlx_img)
	{
		bon->empty_hunger_t->addr
			= mlx_get_data_addr(bon->empty_hunger_t->mlx_img,
				&bon->empty_hunger_t->bpp, &bon->empty_hunger_t->line_l,
				&bon->empty_hunger_t->edian);
	}
	return (get_other_sprites(c_ray, c_map));
}

static int	get_hud_images(t_ray *c_ray, t_map *c_map)
{
	t_bonus_images	*bon;

	bon = c_ray->bonus_images;
	bon->heart_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/heart2.xpm", &bon->heart_t->width,
			&bon->heart_t->height);
	if (bon->heart_t->mlx_img)
	{
		bon->heart_t->addr = mlx_get_data_addr(bon->heart_t->mlx_img,
				&bon->heart_t->bpp, &bon->heart_t->line_l,
				&bon->heart_t->edian);
	}
	bon->hunger_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/bidoche2.xpm", &bon->hunger_t->width,
			&bon->hunger_t->height);
	if (bon->hunger_t->mlx_img)
	{
		bon->hunger_t->addr = mlx_get_data_addr(bon->hunger_t->mlx_img,
				&bon->hunger_t->bpp, &bon->hunger_t->line_l,
				&bon->hunger_t->edian);
	}
	return (get_hud_images_end(c_ray, c_map));
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
	return (get_hud_images(c_ray, c_map));
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
