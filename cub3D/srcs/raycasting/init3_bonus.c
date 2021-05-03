/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:14:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/03 16:16:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	init_bonus_sprites(t_ray *c_ray)
{
	c_ray->bonus_images = malloc(sizeof(t_bonus_images));
	c_ray->bonus_images->heart_t = malloc(sizeof(t_bonus_images));
	c_ray->bonus_images->heart_t->path = NULL;
	c_ray->bonus_images->empty_heart_t = malloc(sizeof(t_bonus_images));
	c_ray->bonus_images->empty_heart_t->path = NULL;
	c_ray->bonus_images->hunger_t = malloc(sizeof(t_bonus_images));
	c_ray->bonus_images->hunger_t->path = NULL;
	c_ray->bonus_images->empty_hunger_t = malloc(sizeof(t_bonus_images));
	c_ray->bonus_images->empty_hunger_t->path = NULL;
	c_ray->bonus_images->good_food = malloc(sizeof(t_image));
	c_ray->bonus_images->good_food->path = NULL;
	c_ray->bonus_images->good_health = malloc(sizeof(t_image));
	c_ray->bonus_images->good_health->path = NULL;
	c_ray->bonus_images->bad_health = malloc(sizeof(t_image));
	c_ray->bonus_images->bad_health->path = NULL;
	c_ray->bonus_images->monster = malloc(sizeof(t_image));
	c_ray->bonus_images->monster->path = NULL;
	c_ray->bonus_images->other_sprite_0 = malloc(sizeof(t_image));
	c_ray->bonus_images->other_sprite_0->path = NULL;
	c_ray->bonus_images->other_sprite_1 = malloc(sizeof(t_image));
	c_ray->bonus_images->other_sprite_1->path = NULL;
	return (0);
}

int	get_index(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}
