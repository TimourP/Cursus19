/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:32:33 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/12 11:58:42 by tpetit           ###   ########.fr       */
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
	const float	angles[4] = {PI * 1.5, PI * 0.5, 0, PI};
	int			i;
	int			j;

	i = -1;
	while (++i < c_ray->c_map->map_h)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w)
		{
			if (is_in_str("NSEW", c_ray->c_map->map[i][j]))
			{
				c_ray->player_angle = angles[get_index("NSEW",
						c_ray->c_map->map[i][j])];
				c_ray->player_delx = sin(c_ray->player_angle) * PLAYER_SPEED;
				c_ray->player_dely = cos(c_ray->player_angle) * PLAYER_SPEED;
				c_ray->player_posx = j + 0.501;
				c_ray->player_posy = i + 0.501;
				c_ray->c_map->map[i][j] = '0';
				return ;
			}
		}
	}
}

void	init_moves(t_ray *c_ray)
{
	c_ray->player_posx = -1;
	c_ray->player_posy = -1;
	c_ray->go_backward = 0;
	c_ray->go_forward = 0;
	c_ray->go_left = 0;
	c_ray->go_right = 0;
	c_ray->turn_left = 0;
	c_ray->turn_right = 0;
	c_ray->look_offset = 0;
	c_ray->look_up = 0;
	c_ray->look_down = 0;
	c_ray->shoot = 0;
	c_ray->all_distances = malloc(sizeof(float) * c_ray->c_map->screen_w);
	if (!c_ray->all_distances)
		exit_message(MALLOC_ERROR);
	c_ray->start_list = NULL;
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

int	init_raycasting(t_ray *c_ray, t_map *c_map)
{
	c_ray->c_map = c_map;
	init_moves(c_ray);
	init_player(c_ray);
	if (c_ray->player_posx == -1 || c_ray->player_posy == -1)
		return (0);
	c_ray->mlx_ptr = mlx_init();
	init_screen_dim(c_ray, c_map);
	c_ray->mlx_win = mlx_new_window(c_ray->mlx_ptr,
			c_ray->c_map->screen_w, c_ray->c_map->screen_h, "CUB3D");
	c_ray->mlx_img = mlx_new_image(c_ray->mlx_ptr,
			c_ray->c_map->screen_w, c_ray->c_map->screen_h);
	c_ray->img_addr = mlx_get_data_addr(c_ray->mlx_img, &c_ray->img_bpp,
			&c_ray->img_line_l, &c_ray->img_edian);
	if (!(get_images(c_ray, c_map)))
		return (0);
	mlx_hook(c_ray->mlx_win, KEY_PRESS_EVENT, 1L << 0, key_press, c_ray);
	mlx_hook(c_ray->mlx_win, KEY_RELEASE_EVENT, 1L << 1, key_release, c_ray);
	mlx_hook(c_ray->mlx_win, CROSS_BTN_EVENT, 1L << 17, exit_button, c_ray);
	mlx_loop_hook(c_ray->mlx_ptr, get_next_frame, c_ray);
	return (1);
}
