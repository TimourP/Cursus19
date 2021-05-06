/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:31:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 15:59:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	check_images(t_ray *c_ray, t_map *c_map)
{
	if (!c_map->north_t->mlx_img || !c_map->south_t->mlx_img
		|| !c_map->west_t->mlx_img || !c_map->east_t->mlx_img
		|| !c_map->sprite_t->mlx_img)
		return (free_on_error(c_map, FILE_ERROR));
	if (!c_ray->sky->mlx_img)
		return (free_on_error(c_map, FILE_ERROR));
	return (1);
}

static int	get_other_sprites4(t_ray *c_ray, t_map *c_map)
{
	t_bonus_images	*bon;

	bon = c_ray->bonus_images;
	bon->game_over->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/game_over.xpm", &bon->game_over->width,
			&bon->game_over->height);
	if (bon->game_over->mlx_img)
	{
		bon->game_over->addr
			= mlx_get_data_addr(bon->game_over->mlx_img,
				&bon->game_over->bpp, &bon->game_over->line_l,
				&bon->game_over->edian);
	}
	return (check_images(c_ray, c_map));
}

static int	get_other_sprites3(t_ray *c_ray, t_map *c_map)
{
	t_bonus_images	*bon;

	bon = c_ray->bonus_images;
	bon->other_sprite_0->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/ghost.xpm", &bon->other_sprite_0->width,
			&bon->other_sprite_0->height);
	if (bon->other_sprite_0->mlx_img)
	{
		bon->other_sprite_0->addr
			= mlx_get_data_addr(bon->other_sprite_0->mlx_img,
				&bon->other_sprite_0->bpp, &bon->other_sprite_0->line_l,
				&bon->other_sprite_0->edian);
	}
	bon->other_sprite_1->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/pillar.xpm", &bon->other_sprite_1->width,
			&bon->other_sprite_1->height);
	if (bon->other_sprite_1->mlx_img)
	{
		bon->other_sprite_1->addr
			= mlx_get_data_addr(bon->other_sprite_1->mlx_img,
				&bon->other_sprite_1->bpp, &bon->other_sprite_1->line_l,
				&bon->other_sprite_1->edian);
	}
	return (get_other_sprites4(c_ray, c_map));
}

static int	get_other_sprites2(t_ray *c_ray, t_map *c_map)
{
	t_bonus_images	*bon;

	bon = c_ray->bonus_images;
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
	return (get_other_sprites3(c_ray, c_map));
}

int	get_other_sprites(t_ray *c_ray, t_map *c_map)
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
	return (get_other_sprites2(c_ray, c_map));
}
