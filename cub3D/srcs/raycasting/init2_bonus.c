/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:08:50 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 19:23:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
				c_ray->player_posx = j + 0.51;
				c_ray->player_posy = i + 0.51;
				c_ray->c_map->map[i][j] = '0';
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
	c_ray->tic = 0;
	c_ray->shoot = 0;
	c_ray->player_health = 10;
	c_ray->player_hunger = 10;
	c_ray->last_remove_life = 0;
	c_ray->last_hit = get_time();
	c_ray->all_distances = malloc(sizeof(float) * c_ray->c_map->screen_w);
	c_ray->start_list = NULL;
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

int	move_mouse(int x, int y, t_ray *c_ray)
{
	if (x > 0 && x < c_ray->screen_w / 2.3 && y > 0 && y < c_ray->screen_h)
		c_ray->turn_left = 1;
	else
		c_ray->turn_left = 0;
	if (x < c_ray->screen_w && x > c_ray->screen_w - c_ray->screen_w
		/ 2.3 && y > 0 && y < c_ray->screen_h)
		c_ray->turn_right = 1;
	else
		c_ray->turn_right = 0;
	if (y > 0 && y < c_ray->screen_h / 2.3 && x > 0 && x < c_ray->screen_w)
		c_ray->look_up = 1;
	else
		c_ray->look_up = 0;
	if (y < c_ray->screen_h && y > c_ray->screen_h - c_ray->screen_h
		/ 2.3 && x > 0 && x < c_ray->screen_w)
		c_ray->look_down = 1;
	else
		c_ray->look_down = 0;
	return (1);
}

int	click_shot(int btn, int x, int y, t_ray *c_ray)
{
	if (btn == 1)
		c_ray->shoot = 1;
	return (1);
}
