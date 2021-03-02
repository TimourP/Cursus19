/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:24:32 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/02 10:41:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		map_error(t_map *c_map)
{
	int i;
	int j;

	i = -1;
	while (++i < c_map->map_h)
	{
		j = -1;
		while (++j < c_map->map_w)
		{
			if (j == 0 || j == c_map->map_w - 1 || i == 0 ||
				i == c_map->map_h - 1)
			{
				if (c_map->map[i][j] == '0')
					return (0);
			}
			else if (c_map->map[i][j] == '0' &&
				(c_map->map[i - 1][j - 1] == ' ' || c_map->map[i - 1][j] == ' '
				|| c_map->map[i - 1][j + 1] == ' ' ||
				c_map->map[i][j - 1] == ' ' || c_map->map[i][j + 1] == ' ' ||
				c_map->map[i + 1][j - 1] == ' ' || c_map->map[i + 1][j] == ' '
				|| c_map->map[i + 1][j + 1] == ' '))
				return (0);
		}
	}
	return (1);
}
