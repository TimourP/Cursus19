/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:19:40 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/26 15:46:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_next_move(t_ray *c_ray, float x_diff, float y_diff)
{
	float		next_posx;
	float		next_posy;

	next_posx = c_ray->player_posx + x_diff;
	next_posy = c_ray->player_posy + y_diff;
	if (!is_in_str("0abcNSEW",
			c_ray->c_map->map[(int)next_posy][(int)next_posx]))
	{
		if (is_in_str("0abcNSEW",
				c_ray->c_map->map[(int)next_posy][(int)c_ray->player_posx]))
			c_ray->player_posy += y_diff;
		else if (is_in_str("0abcNSEW",
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

void	set_speed(t_ray *c_ray)
{
	struct timespec		spec;
	long int			time;
	float				fps;

	clock_gettime(CLOCK_REALTIME, &spec);
	time = (long int)(spec.tv_sec * 1000 + round(spec.tv_nsec / 1.0e6));
	fps = 600.0 / (int)(time - c_ray->last_frame);
	c_ray->last_frame = time;
	c_ray->player_speed = PLAYER_BONUS_SPEED / fps;
	if (c_ray->player_speed < 0)
		c_ray->player_speed = 0;
	if (c_ray->player_speed > 2)
		c_ray->player_speed = 2;
	c_ray->player_delx = sin(c_ray->player_angle) * c_ray->player_speed;
	c_ray->player_dely = cos(c_ray->player_angle) * c_ray->player_speed;
}

int	random_between(int min, int max)
{
	const float	ra = (float)rand() / INT_MAX;

	return ((max - min + 1) * ra + min);
}

static void	play_foot_step(void)
{
	if (random_between(0, 1))
		system("afplay sounds/walk.mp3 &>/dev/null &");
	else
		system("afplay sounds/walk2.mp3 &>/dev/null &");
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

static void	proceed_next_frame(t_ray *c_ray, int bool)
{
	static int	decrease;
	int			x;
	int			y;
	char		to_put;

	if (bool || BONUS)
	{
		if (BONUS)
		{
			set_speed(c_ray);
			x = c_ray->player_posx;
			y = c_ray->player_posy;
			if (is_in_str("abc", c_ray->c_map->map[y][x]))
			{
				to_put = c_ray->c_map->map[y][x];
				if (c_ray->c_map->map[y][x] == 'a')
					c_ray->player_hunger += 1;
				else if (c_ray->c_map->map[y][x] == 'b')
					c_ray->player_health += 1;
				else if (c_ray->c_map->map[y][x] == 'c')
					c_ray->player_health -= 1;
				c_ray->c_map->map[y][x] = '0';
				reput_bonus(c_ray, to_put);
			}
		}
		c_ray->tic = c_ray->tic + 1 - 2 * decrease;
		if (c_ray->tic >= 100)
			decrease = 1;
		else if (c_ray->tic <= 0)
			decrease = 0;
		if (c_ray->tic == 50)
		{
			if (c_ray->player_hunger > 0)
				c_ray->player_hunger -= 1;
			else
				c_ray->player_health -= 1;
		}
		if (c_ray->player_health == 0)
		{
			printf("You die...\n");
			exit(0);
		}
		draw_game(c_ray);
		if (BONUS)
		{
			minimap(c_ray);
			draw_life_bar(c_ray);
			draw_hunger_bar(c_ray);
		}
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
	if ((last_x != c_ray->player_posx
		|| last_y != c_ray->player_posy) && c_ray->tic % 8 == 0)
		play_foot_step();
	last_x = c_ray->player_posx;
	last_y = c_ray->player_posy;
	last_angle = c_ray->player_angle;
	last_offset = c_ray->look_offset;
	return (1);
}
