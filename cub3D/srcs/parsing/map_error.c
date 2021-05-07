/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:24:32 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/07 11:46:30 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	map_error_end(t_map *c_map, const char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (++i < c_map->map_h)
	{
		j = -1;
		while (++j < c_map->map_w)
			if (is_in_str("NSEW", map[i][j]))
				count++;
	}
	if (count != 1)
		return (0);
	return (1);
}

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
			if (!is_in_str("01NSEW2 ", map[i][j]))
				return (0);
			if (j == 0 || j == c_map->map_w - 1 || i == 0
				|| i == c_map->map_h - 1)
			{
				if (is_in_str("0NSEW2", map[i][j]))
					return (0);
			}
			else if (is_in_str("0NSEW2", map[i][j]) && (
					map[i - 1][j] == ' ' || map[i][j - 1] == ' '
					|| map[i][j + 1] == ' ' || map[i + 1][j] == ' '))
				return (0);
		}
	}
	return (map_error_end(c_map, map));
}

/*
 * else if (map[i][j] == '0' && (map[i - 1][j - 1] == ' '
 * 					|| map[i - 1][j] == ' ' || map[i - 1][j + 1] == ' '
 * 					|| map[i][j - 1] == ' ' || map[i][j + 1] == ' '
 * 					|| map[i + 1][j - 1] == ' ' || map[i + 1][j] == ' '
 * 					|| map[i + 1][j + 1] == ' '))
*/