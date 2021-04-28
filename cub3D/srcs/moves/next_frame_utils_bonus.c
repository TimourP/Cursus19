/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:01:58 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/28 20:38:11 by tpetit           ###   ########.fr       */
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

void	move_monsters(t_ray *c_ray, t_monster_list *lst)
{
	float	dx;
	float	dy;
	float	move_x;
	float	move_y;
	const float speed = c_ray->player_speed / 4;
	float	ratio_x;
	float	ratio_y;

	while (lst)
	{
		dx = c_ray->player_posx - lst->content->x;
		dy = c_ray->player_posy - lst->content->y;
		ratio_x = fabs(dx) > fabs(dy) ? 1 : fabs(dx) / fabs(dy);
		ratio_y = fabs(dx) > fabs(dy) ? fabs(dy) / fabs(dx) : 1;
		if (sqrt(pow(dx, 2) + pow(dy, 2)) > 2)
		{
			move_x = fabs(dx) > speed ? speed : dx;
			move_y = fabs(dy) > speed ? speed : dy;
			if (dx < 0)
				lst->content->x = lst->content->x - move_x * ratio_x;
			else
				lst->content->x = lst->content->x + move_x * ratio_x;
			if (dy < 0)
				lst->content->y = lst->content->y - move_y * ratio_y;
			else
				lst->content->y = lst->content->y + move_y * ratio_y;	
		}
		lst = lst->next;
	}
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
	c_ray->player_speed = PLAYER_SPEED / fps;
	if (c_ray->player_speed < 0)
		c_ray->player_speed = 0;
	if (c_ray->player_speed > 2)
		c_ray->player_speed = 2;
	c_ray->player_delx = sin(c_ray->player_angle) * c_ray->player_speed;
	c_ray->player_dely = cos(c_ray->player_angle) * c_ray->player_speed;
	move_monsters(c_ray, c_ray->monster_list);
}

long int	get_time(void)
{
	struct timespec		spec;

	clock_gettime(CLOCK_REALTIME, &spec);
	return ((long int)(spec.tv_sec * 1000 + round(spec.tv_nsec / 1.0e6)));
}
