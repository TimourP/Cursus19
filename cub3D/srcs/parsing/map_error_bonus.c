/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:21:54 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/07 11:26:57 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_error(t_map *c_map)
{
	int			i;
	int			j;
	const char	**map = (const char **)c_map->map;

	i = -1;
	while (++i < c_map->map_h)
	{
		j = -1;
		while (++j < c_map->map_w)
		{
			if (!is_in_str("01NSEW234abcM ", map[i][j]))
				return (0);
			if (j == 0 || j == c_map->map_w - 1 || i == 0
				|| i == c_map->map_h - 1)
			{
				if (is_in_str("0NSEW234abcM", map[i][j]))
					return (0);
			}
			else if (is_in_str("0NSEW234abcM", map[i][j]) && (
					map[i - 1][j] == ' ' || map[i][j - 1] == ' '
					|| map[i][j + 1] == ' ' || map[i + 1][j] == ' '))
				return (0);
		}
	}
	return (1);
}
