/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:12:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/26 13:25:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_images(t_ray *c_ray, t_map *c_map)
{
	if (!c_map->north_t->mlx_img || !c_map->south_t->mlx_img
		|| !c_map->west_t->mlx_img || !c_map->east_t->mlx_img
		|| !c_map->sprite_t->mlx_img || !c_map->heart_t->mlx_img
		|| !c_map->hunger_t->mlx_img || !c_map->empty_heart_t->mlx_img
		|| !c_map->empty_hunger_t->mlx_img)
		return (free_on_error(c_map, FILE_ERROR));
	if (BONUS && !c_ray->sky->mlx_img)
		return (free_on_error(c_map, FILE_ERROR));
	return (1);
}

static int	get_other_sprites(t_ray *c_ray, t_map *c_map)
{
	t_bonus_images	*bon;

	bon = c_ray->bonus_images;
	bon->good_food->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/chicken.xpm", &bon->good_food->width,
			&bon->good_food->height);
	if (bon->good_food->mlx_img)
	{
		bon->good_food->addr = mlx_get_data_addr(bon->good_food->mlx_img,
				&bon->good_food->bpp, &bon->good_food->line_l,
				&bon->good_food->edian);
	}
	bon->good_health->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/floor_heart.xpm", &bon->good_health->width,
			&bon->good_health->height);
	if (bon->good_health->mlx_img)
	{
		bon->good_health->addr = mlx_get_data_addr(bon->good_health->mlx_img,
				&bon->good_health->bpp, &bon->good_health->line_l,
				&bon->good_health->edian);
	}
	bon->bad_health->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/fire.xpm", &bon->bad_health->width,
			&bon->bad_health->height);
	if (bon->bad_health->mlx_img)
	{
		bon->bad_health->addr = mlx_get_data_addr(bon->bad_health->mlx_img,
				&bon->bad_health->bpp, &bon->bad_health->line_l,
				&bon->bad_health->edian);
	}
	bon->monster->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/floor_heart.xpm", &bon->monster->width,
			&bon->monster->height);
	if (bon->monster->mlx_img)
	{
		bon->monster->addr = mlx_get_data_addr(bon->monster->mlx_img,
				&bon->monster->bpp, &bon->monster->line_l,
				&bon->monster->edian);
	}
	bon->other_sprite_0->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/tree.xpm", &bon->other_sprite_0->width,
			&bon->other_sprite_0->height);
	if (bon->other_sprite_0->mlx_img)
	{
		bon->other_sprite_0->addr = mlx_get_data_addr(bon->other_sprite_0->mlx_img,
				&bon->other_sprite_0->bpp, &bon->other_sprite_0->line_l,
				&bon->other_sprite_0->edian);
	}
	bon->other_sprite_1->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/pillar.xpm", &bon->other_sprite_1->width,
			&bon->other_sprite_1->height);
	if (bon->other_sprite_1->mlx_img)
	{
		bon->other_sprite_1->addr = mlx_get_data_addr(bon->other_sprite_1->mlx_img,
				&bon->other_sprite_1->bpp, &bon->other_sprite_1->line_l,
				&bon->other_sprite_1->edian);
	}
	return (check_images(c_ray, c_map));
}

static int	get_hud_images(t_ray *c_ray, t_map *c_map)
{
	c_map->heart_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/heart2.xpm", &c_map->heart_t->width,
			&c_map->heart_t->height);
	if (c_map->heart_t->mlx_img)
	{
		c_map->heart_t->addr = mlx_get_data_addr(c_map->heart_t->mlx_img,
				&c_map->heart_t->bpp, &c_map->heart_t->line_l,
				&c_map->heart_t->edian);
	}
	c_map->hunger_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/bidoche2.xpm", &c_map->hunger_t->width,
			&c_map->hunger_t->height);
	if (c_map->hunger_t->mlx_img)
	{
		c_map->hunger_t->addr = mlx_get_data_addr(c_map->hunger_t->mlx_img,
				&c_map->hunger_t->bpp, &c_map->hunger_t->line_l,
				&c_map->hunger_t->edian);
	}
	c_map->empty_heart_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/empty_heart.xpm", &c_map->empty_heart_t->width,
			&c_map->empty_heart_t->height);
	if (c_map->empty_heart_t->mlx_img)
	{
		c_map->empty_heart_t->addr = mlx_get_data_addr(c_map->empty_heart_t->mlx_img,
				&c_map->empty_heart_t->bpp, &c_map->empty_heart_t->line_l,
				&c_map->empty_heart_t->edian);
	}
	c_map->empty_hunger_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/empty_hunger.xpm", &c_map->empty_hunger_t->width,
			&c_map->empty_hunger_t->height);
	if (c_map->empty_hunger_t->mlx_img)
	{
		c_map->empty_hunger_t->addr = mlx_get_data_addr(c_map->empty_hunger_t->mlx_img,
				&c_map->empty_hunger_t->bpp, &c_map->empty_hunger_t->line_l,
				&c_map->empty_hunger_t->edian);
	}
	return (get_other_sprites(c_ray, c_map));
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
