/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:42:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 20:18:23 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int	init_monters_list_loop(t_ray *c_ray, int i, int j, int index)
{
	t_monster		*new_monster;

	new_monster = malloc(sizeof(t_monster));
	new_monster->x = j + 0.5;
	new_monster->y = i + 0.5;
	new_monster->img = c_ray->bonus_images->other_sprite_0;
	new_monster->id = index;
	new_monster->shot_count = 0;
	ft_monster_add_back(&c_ray->monster_list, ft_monster_new(new_monster));
	c_ray->c_map->map[i][j] = '0';
	return (1);
}

int	init_monsters_list(t_ray *c_ray)
{
	int				i;
	int				j;
	int				index;

	i = -1;
	index = 0;
	c_ray->monster_list = NULL;
	while (++i < c_ray->c_map->map_h)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w)
		{
			if (c_ray->c_map->map[i][j] == 'M')
			{
				init_monters_list_loop(c_ray, i, j, index);
				index++;
			}
		}
	}
	return (0);
}

static void	init_screen_dim(t_ray *c_ray, t_map *c_map)
{
	int	max_height;
	int	max_width;

	mlx_get_screen_size(c_ray->mlx_ptr, &max_width, &max_height);
	if (max_width < c_ray->c_map->screen_w)
		c_ray->c_map->screen_w = max_width;
	if (max_height < c_ray->c_map->screen_h)
		c_ray->c_map->screen_h = max_height;
	c_ray->screen_h = c_map->screen_h;
	c_ray->screen_w = c_map->screen_w;
}

static void	init_hook(t_ray *c_ray)
{
	mlx_hook(c_ray->mlx_win, KEY_PRESS_EVENT, 1L << 0, key_press, c_ray);
	mlx_hook(c_ray->mlx_win, KEY_RELEASE_EVENT, 1L << 1, key_release, c_ray);
	mlx_hook(c_ray->mlx_win, CROSS_BTN_EVENT, 1L << 17, exit_button, c_ray);
	mlx_hook(c_ray->mlx_win, 6, 1L << 6, move_mouse, c_ray);
	mlx_hook(c_ray->mlx_win, 4, 1L << 2, click_shot, c_ray);
	mlx_loop_hook(c_ray->mlx_ptr, get_next_frame, c_ray);
}

int	init_raycasting(t_ray *c_ray, t_map *c_map)
{
	c_ray->c_map = c_map;
	init_moves(c_ray);
	init_player(c_ray);
	c_ray->mlx_ptr = mlx_init();
	init_screen_dim(c_ray, c_map);
	c_ray->mlx_win = mlx_new_window(c_ray->mlx_ptr,
			c_ray->c_map->screen_w, c_ray->c_map->screen_h, "CUB3D");
	c_ray->mlx_img = mlx_new_image(c_ray->mlx_ptr,
			c_ray->c_map->screen_w, c_ray->c_map->screen_h);
	c_ray->img_addr = mlx_get_data_addr(c_ray->mlx_img, &c_ray->img_bpp,
			&c_ray->img_line_l, &c_ray->img_edian);
	init_bonus_sprites(c_ray);
	get_sky(c_ray);
	if (!(get_images(c_ray, c_map)))
		return (0);
	init_monsters_list(c_ray);
	init_hook(c_ray);
	return (1);
}
