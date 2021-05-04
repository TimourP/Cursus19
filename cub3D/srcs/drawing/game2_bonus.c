/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:09:57 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/03 16:54:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void	get_shot_end(t_ray *c_ray, t_monster_list *m_lst, int id)
{
	while (m_lst)
	{
		if (id != -1 && m_lst->content->id == id)
		{
			m_lst->content->shot_count = m_lst->content->shot_count + 1;
			if (m_lst->content->shot_count > 4)
			{
				m_lst->content->x = random_between(0, c_ray->c_map->map_w);
				m_lst->content->y = random_between(0, c_ray->c_map->map_h);
				m_lst->content->shot_count = 0;
			}
		}
		m_lst = m_lst->next;
	}
}

void	get_shot(t_ray *c_ray, t_sprite_list *s_lst, t_monster_list *m_lst)
{
	int			id;
	t_sprite	*elem;
	const int	x = c_ray->screen_w / 2;
	const int	y = c_ray->screen_h / 2;

	c_ray->shoot = 0;
	id = -1;
	system("afplay sounds/gun_shot.mp3 &>/dev/null &");
	while (s_lst)
	{
		if (s_lst->content->id != -1)
		{
			elem = s_lst->content;
			if (elem->start_x < x && elem->end_x > x && elem->start_y
				< y && elem->end_y > y && c_ray->all_distances[x]
				> elem->distance)
				id = elem->id;
		}
		s_lst = s_lst->next;
	}
	get_shot_end(c_ray, m_lst, id);
}
