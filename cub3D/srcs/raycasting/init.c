/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:32:33 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/31 10:06:12 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_index(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (0);
}

void	init_player(t_ray *c_ray)
{
	const float	angles[4] = {-PI / 2, PI / 2, 0, PI};
	int			i;
	int			j;

	i = -1;
	while (++i < c_ray->c_map->map_h + 1)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w + i)
		{
			if (is_in_str("NSEW", c_ray->c_map->map[i][j]))
			{
				c_ray->player_angle = angles[get_index("NSEW",
						c_ray->c_map->map[i][j])];
				c_ray->player_delx = sin(c_ray->player_angle) * PLAYER_SPEED;
				c_ray->player_dely = cos(c_ray->player_angle) * PLAYER_SPEED;
				c_ray->player_posx = j + 0.5;
				c_ray->player_posy = i + 0.5;
				return ;
			}
		}
	}
}

void	init_moves(t_ray *c_ray)
{
	c_ray->go_backward = 0;
	c_ray->go_forward = 0;
	c_ray->go_left = 0;
	c_ray->go_right = 0;
	c_ray->turn_left = 0;
	c_ray->turn_right = 0;
	c_ray->look_offset = 0;
	c_ray->look_up = 0;
	c_ray->look_down = 0;
}

int check_images(t_ray *c_ray, t_map *c_map)
{
	if (!c_map->north_t->mlx_img || !c_map->north_t->mlx_img
		|| !c_map->north_t->mlx_img || !c_map->north_t->mlx_img)
		return (free_on_error(c_map, FILE_ERROR));
	if (BONUS && !c_ray->sky->mlx_img)
		return (free_on_error(c_map, FILE_ERROR));
	return (1);
}

int	get_images_end(t_ray *c_ray, t_map *c_map)
{
	c_map->west_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->west_t->path, &c_map->west_t->width,
			&c_map->west_t->height);
	c_map->west_t->addr = mlx_get_data_addr(c_map->west_t->mlx_img,
			&c_map->west_t->bpp, &c_map->west_t->line_l,
			&c_map->west_t->edian);
	c_map->south_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->south_t->path, &c_map->south_t->width,
			&c_map->south_t->height);
	c_map->south_t->addr = mlx_get_data_addr(c_map->south_t->mlx_img,
			&c_map->south_t->bpp, &c_map->south_t->line_l,
			&c_map->south_t->edian);
	return (check_images(c_ray, c_map));
}

int	get_images(t_ray *c_ray, t_map *c_map)
{
	c_map->north_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->north_t->path, &c_map->north_t->width,
			&c_map->north_t->height);
	c_map->north_t->addr = mlx_get_data_addr(c_map->north_t->mlx_img,
			&c_map->north_t->bpp, &c_map->north_t->line_l,
			&c_map->north_t->edian);
	c_map->east_t->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			c_map->east_t->path, &c_map->east_t->width,
			&c_map->east_t->height);
	c_map->east_t->addr = mlx_get_data_addr(c_map->east_t->mlx_img,
			&c_map->east_t->bpp, &c_map->east_t->line_l,
			&c_map->east_t->edian);
	return (get_images_end(c_ray, c_map));
}

int	get_sky(t_ray *c_ray)
{
	c_ray->sky = malloc(sizeof(t_image));
	c_ray->sky->mlx_img = mlx_xpm_file_to_image(c_ray->mlx_ptr,
			"images/sky.xpm", &c_ray->sky->width, &c_ray->sky->height);
	c_ray->sky->addr = mlx_get_data_addr(c_ray->sky->mlx_img,
			&c_ray->sky->bpp, &c_ray->sky->line_l,
			&c_ray->sky->edian);
	return (1);
}

int	init_raycasting(t_ray *c_ray, t_map *c_map)
{
	c_ray->c_map = c_map;
	init_moves(c_ray);
	init_player(c_ray);
	c_ray->screen_h = c_map->screen_h;
	c_ray->screen_w = c_map->screen_w;
	c_ray->mlx_ptr = mlx_init();
	c_ray->mlx_win = mlx_new_window(c_ray->mlx_ptr,
			c_map->screen_w, c_map->screen_h, "CUB3D");
	c_ray->mlx_img = mlx_new_image(c_ray->mlx_ptr,
			c_map->screen_w, c_map->screen_h);
	c_ray->img_addr = mlx_get_data_addr(c_ray->mlx_img, &c_ray->img_bpp,
			&c_ray->img_line_l, &c_ray->img_edian);
	if (BONUS)
		get_sky(c_ray);
	if (!(get_images(c_ray, c_map)))
		return (0);
	mlx_hook(c_ray->mlx_win, KEY_PRESS_EVENT, 1L << 0, key_press, c_ray);
	mlx_hook(c_ray->mlx_win, KEY_RELEASE_EVENT, 1L << 1, key_release, c_ray);
	mlx_hook(c_ray->mlx_win, CROSS_BTN_EVENT, 1L << 17, exit_button, c_ray);
	mlx_loop_hook(c_ray->mlx_ptr, get_next_frame, c_ray);
	return (1);
}
