/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:39:24 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/07 13:19:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d_bonus.h"

int	main_error(int argc, char **argv, t_ray *c_ray)
{
	if (argc == 1 || !argv[1])
	{
		printf("Error\nPlease enter the path of the map as first argument\n");
		return (0);
	}
	else if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
	{
		printf("Error\nMap files must be in .cub format\n");
		return (0);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		c_ray->save = 1;
	else if (argc == 3)
	{
		printf("Error\nSecond argument must be --save\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*c_map;
	t_ray	*c_ray;

	c_map = malloc(sizeof(t_map));
	c_ray = malloc(sizeof(t_ray));
	c_ray->save = 0;
	if (!main_error(argc, argv, c_ray))
		return (-1);
	if (!parse_map(c_map, argv[1]))
		return (-1);
	if (!check_parsing_error(c_map))
		return (-1);
	if (!(init_raycasting(c_ray, c_map)))
		return (-1);
	if (!c_ray->save)
	{
		system("afplay sounds/ambiance.mp3 &>/dev/null &");
		mlx_loop(c_ray->mlx_ptr);
	}
	else
		get_next_frame(c_ray);
	return (0);
}
