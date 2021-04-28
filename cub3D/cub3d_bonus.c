/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:39:24 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/28 20:05:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int	main_error(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*c_map;
	t_ray	*c_ray;

	c_map = malloc(sizeof(t_map));
	c_ray = malloc(sizeof(t_ray));
	if (!main_error(argc, argv))
		return (-1);
	if (!parse_map(c_map, argv[1]))
		return (-1);
	if (!check_parsing_error(c_map))
		return (-1);
	if (!(init_raycasting(c_ray, c_map)))
		return (-1);
	//system("afplay sounds/ambiance.mp3 &>/dev/null &");
	mlx_loop(c_ray->mlx_ptr);
	return (0);
}
