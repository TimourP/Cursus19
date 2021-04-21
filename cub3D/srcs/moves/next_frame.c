/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:19:40 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/21 16:28:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_next_move(t_ray *c_ray, float x_diff, float y_diff)
{
	float		next_posx;
	float		next_posy;

	next_posx = c_ray->player_posx + x_diff;
	next_posy = c_ray->player_posy + y_diff;
	if (!is_in_str("0NSEW",
			c_ray->c_map->map[(int)next_posy][(int)next_posx]))
	{
		if (is_in_str("0NSEW",
				c_ray->c_map->map[(int)next_posy][(int)c_ray->player_posx]))
			c_ray->player_posy += y_diff;
		else if (is_in_str("0NSEW",
				c_ray->c_map->map[(int)c_ray->player_posy][(int)next_posx]))
			c_ray->player_posx += x_diff;
		return ;
	}
	c_ray->player_posx += x_diff;
	c_ray->player_posy += y_diff;
}

static void	proceed_angles_look(t_ray *c_ray)
{
	if (c_ray->turn_right)
	{
		c_ray->player_angle += PLAYER_ROTATION;
		if (c_ray->player_angle > 2 * PI)
			c_ray->player_angle -= 2 * PI;
		c_ray->player_delx = sin(c_ray->player_angle) * PLAYER_SPEED;
		c_ray->player_dely = cos(c_ray->player_angle) * PLAYER_SPEED;
	}
	if (c_ray->turn_left)
	{
		c_ray->player_angle -= PLAYER_ROTATION;
		if (c_ray->player_angle < 0)
			c_ray->player_angle += 2 * PI;
		c_ray->player_delx = sin(c_ray->player_angle) * PLAYER_SPEED;
		c_ray->player_dely = cos(c_ray->player_angle) * PLAYER_SPEED;
	}
	if (c_ray->look_up && c_ray->look_offset < MAX_OFFSET)
		c_ray->look_offset += OFFSET_SPEED;
	if (c_ray->look_down && c_ray->look_offset > -MAX_OFFSET)
		c_ray->look_offset -= OFFSET_SPEED;
}

static void	proceed_next_frame(t_ray *c_ray, int bool)
{
	static int		decrease;

	if (bool || BONUS)
	{
		c_ray->tic = c_ray->tic + 1 - 2 * decrease;
		if (c_ray->tic >= 100)
			decrease = 1;
		else if (c_ray->tic <= 0)
			decrease = 0;
		draw_game(c_ray);
		if (BONUS || 1)
			minimap(c_ray);
		mlx_put_image_to_window(c_ray->mlx_ptr, c_ray->mlx_win,
			c_ray->mlx_img, 0, 0);
	}
}

int	get_next_frame(t_ray *c_ray)
{
	static float	last_x;
	static float	last_y;
	static float	last_angle;
	static int		last_offset;

	if (c_ray->go_forward)
		check_next_move(c_ray, c_ray->player_dely, c_ray->player_delx);
	if (c_ray->go_backward)
		check_next_move(c_ray, -c_ray->player_dely, -c_ray->player_delx);
	if (c_ray->go_left)
		check_next_move(c_ray, c_ray->player_delx, -c_ray->player_dely);
	if (c_ray->go_right)
		check_next_move(c_ray, -c_ray->player_delx, c_ray->player_dely);
	proceed_angles_look(c_ray);
	proceed_next_frame(c_ray, last_x != c_ray->player_posx
		|| last_y != c_ray->player_posy || last_angle != c_ray->player_angle
		|| last_offset != c_ray->look_offset);
	last_x = c_ray->player_posx;
	last_y = c_ray->player_posy;
	last_angle = c_ray->player_angle;
	last_offset = c_ray->look_offset;
	return (1);
}
