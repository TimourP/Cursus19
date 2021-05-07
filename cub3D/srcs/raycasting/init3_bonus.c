/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:14:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/07 14:22:42 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	init_bonus_sprites2(t_ray *c_ray)
{
	t_bonus_images	*b;

	b = c_ray->bonus_images;
	c_ray->bonus_images->monster = malloc(sizeof(t_image));
	if (c_ray->bonus_images->monster)
		c_ray->bonus_images->monster->path = NULL;
	c_ray->bonus_images->other_sprite_0 = malloc(sizeof(t_image));
	if (c_ray->bonus_images->other_sprite_0)
		c_ray->bonus_images->other_sprite_0->path = NULL;
	c_ray->bonus_images->other_sprite_1 = malloc(sizeof(t_image));
	if (c_ray->bonus_images->other_sprite_1)
		c_ray->bonus_images->other_sprite_1->path = NULL;
	c_ray->bonus_images->game_over = malloc(sizeof(t_image));
	if (c_ray->bonus_images->game_over)
		c_ray->bonus_images->game_over->path = NULL;
	if (!b->bad_health || !b->empty_heart_t || !b->empty_hunger_t
		|| !b->game_over || !b->good_food || !b->good_health
		|| !b->heart_t || !b->hunger_t || !b->monster
		|| !b->other_sprite_0 || !b->other_sprite_1)
		exit_message(MALLOC_ERROR);
	return (1);
}

int	init_bonus_sprites(t_ray *c_ray)
{
	c_ray->bonus_images = malloc(sizeof(t_bonus_images));
	if (!c_ray->bonus_images)
		exit_message(MALLOC_ERROR);
	c_ray->bonus_images->heart_t = malloc(sizeof(t_bonus_images));
	if (c_ray->bonus_images->heart_t)
		c_ray->bonus_images->heart_t->path = NULL;
	c_ray->bonus_images->empty_heart_t = malloc(sizeof(t_bonus_images));
	if (c_ray->bonus_images->empty_heart_t)
		c_ray->bonus_images->empty_heart_t->path = NULL;
	c_ray->bonus_images->hunger_t = malloc(sizeof(t_bonus_images));
	if (c_ray->bonus_images->hunger_t)
		c_ray->bonus_images->hunger_t->path = NULL;
	c_ray->bonus_images->empty_hunger_t = malloc(sizeof(t_bonus_images));
	if (c_ray->bonus_images->empty_hunger_t)
		c_ray->bonus_images->empty_hunger_t->path = NULL;
	c_ray->bonus_images->good_food = malloc(sizeof(t_image));
	if (c_ray->bonus_images->good_food)
		c_ray->bonus_images->good_food->path = NULL;
	c_ray->bonus_images->good_health = malloc(sizeof(t_image));
	if (c_ray->bonus_images->good_health)
		c_ray->bonus_images->good_health->path = NULL;
	c_ray->bonus_images->bad_health = malloc(sizeof(t_image));
	if (c_ray->bonus_images->bad_health)
		c_ray->bonus_images->bad_health->path = NULL;
	return (init_bonus_sprites2(c_ray));
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
