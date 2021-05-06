/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame_utils2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:25:32 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 12:28:17 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	random_between(int min, int max)
{
	const float	ra = (float)rand() / INT_MAX;

	return ((max - min + 1) * ra + min);
}

void	play_foot_step(void)
{
	if (random_between(0, 1))
		system("afplay sounds/walk.mp3 &>/dev/null &");
	else
		system("afplay sounds/walk2.mp3 &>/dev/null &");
}

void	death(t_ray *c_ray)
{
	static int	dead;
	const float	y_ratio = (float)c_ray->bonus_images->game_over->height / c_ray->screen_h;
	const float	x_ratio = (float)c_ray->bonus_images->game_over->width / c_ray->screen_w;
	int			i;
	int			j;
	int			color;

	if (!dead)
	{
		printf("You die...\n");
		system("afplay sounds/end_game.mp3 &>/dev/null &");
		i = -1;
		while (++i < c_ray->screen_h)
		{
			j = -1;
			while (++j < c_ray->screen_w)
			{
				get_pixel(c_ray->bonus_images->game_over, j * x_ratio, i * y_ratio, &color);
				draw_pixel(c_ray, j, i, color);
			}
		}
		mlx_put_image_to_window(c_ray->mlx_ptr, c_ray->mlx_win,
				c_ray->mlx_img, 0, 0);
	}
	dead = 1;
}

static void	reput_bonus(t_ray *c_ray, char bonus)
{
	int	put;
	int	x;
	int	y;

	put = 0;
	while (!put)
	{
		x = random_between(1, c_ray->c_map->map_w - 1);
		y = random_between(1, c_ray->c_map->map_h - 1);
		if (c_ray->c_map->map[y][x] == '0')
		{
			c_ray->c_map->map[y][x] = bonus;
			put = 1;
		}
	}
}

void	proceed_consumable_sprites(t_ray *c_ray)
{
	int			x;
	int			y;
	char		to_put;

	x = c_ray->player_posx;
	y = c_ray->player_posy;
	if (is_in_str("abc", c_ray->c_map->map[y][x]))
	{
		to_put = c_ray->c_map->map[y][x];
		if (c_ray->c_map->map[y][x] == 'a')
		{
			c_ray->player_hunger += 1;
			system("afplay sounds/eat2.mp3 &>/dev/null &");
		}
		else if (c_ray->c_map->map[y][x] == 'b')
			c_ray->player_health += 1;
		else if (c_ray->c_map->map[y][x] == 'c')
		{
			c_ray->player_health -= 1;
			system("afplay sounds/classic_hurt.mp3 &>/dev/null &");
		}
		c_ray->c_map->map[y][x] = '0';
		reput_bonus(c_ray, to_put);
	}
}
