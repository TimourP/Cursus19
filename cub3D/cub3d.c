/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:22:14 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 14:24:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main_error(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	c_map;
	t_ray	c_ray;

	if (!main_error(argc, argv))
		return (-1);
	if (!parse_map(&c_map, argv[1]))
		return (-1);
	if (!(init_raycasting(&c_ray, &c_map)))
		return (-1);
	print_map_struct(&c_map);
	mlx_loop(c_ray.mlx_ptr);
	free_t_map(&c_map);
	return (0);
}
