/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:01:58 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/03 13:35:58 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	set_ratios(float *ratio_x, float *ratio_y, float d_xy[2])
{
	if (fabs(d_xy[0]) > fabs(d_xy[1]))
	{
		*ratio_x = 1;
		*ratio_y = fabs(d_xy[1]) / fabs(d_xy[0]);
	}
	else
	{
		*ratio_x = fabs(d_xy[0]) / fabs(d_xy[1]);
		*ratio_y = 1;
	}
}

static void	set_moves(float d_xy[2], float speed, float *m_x, float *m_y)
{
	if (fabs(d_xy[0]) > speed)
		*m_x = speed;
	else
		*m_x = d_xy[0];
	if (fabs(d_xy[1]) > speed)
		*m_y = speed;
	else
		*m_y = d_xy[1];
}

void	move_monsters(t_ray *c_ray, t_monster_list *lst)
{
	float		d_xy[2];
	float		m_xy[2];
	const float	speed = c_ray->player_speed / 4;
	float		ratio_x;
	float		ratio_y;

	while (lst)
	{
		d_xy[0] = c_ray->player_posx - lst->content->x;
		d_xy[1] = c_ray->player_posy - lst->content->y;
		set_ratios(&ratio_x, &ratio_y, d_xy);
		if (sqrt(pow(d_xy[0], 2) + pow(d_xy[1], 2)) > 2)
		{
			set_moves(d_xy, speed, &m_xy[0], &m_xy[1]);
			if (d_xy[0] < 0)
				lst->content->x = lst->content->x - m_xy[0] * ratio_x;
			else
				lst->content->x = lst->content->x + m_xy[0] * ratio_x;
			if (d_xy[1] < 0)
				lst->content->y = lst->content->y - m_xy[1] * ratio_y;
			else
				lst->content->y = lst->content->y + m_xy[1] * ratio_y;
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
