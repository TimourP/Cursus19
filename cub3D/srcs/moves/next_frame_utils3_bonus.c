/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_frame_utils3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:36:25 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 16:43:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	play_foot_step(void)
{
	if (random_between(0, 1))
		system("afplay sounds/walk.mp3 &>/dev/null &");
	else
		system("afplay sounds/walk2.mp3 &>/dev/null &");
}

void	set_moves(float d_xy[2], float speed, float *m_x, float *m_y)
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
