/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:36:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/22 15:17:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map_struct(t_map *c_map)
{
	printf("screen width : %d\n", c_map->screen_w);
	printf("screen height : %d\n", c_map->screen_h);
	printf("map width : %d\n", c_map->map_w);
	printf("map height : %d\n", c_map->map_h);
	printf("south texture : %s\n", c_map->south_t);
	printf("north texture : %s\n", c_map->north_t);
	printf("west texture : %s\n", c_map->west_t);
	printf("east texture : %s\n", c_map->east_t);
	printf("floor texture : %s\n", c_map->floor_t);
	printf("ceiling texture : %s\n", c_map->ceiling_t);
}

void	print_map(t_map *c_map)
{
	int i;

	i = -1;
	while (++i < c_map->map_h)
		printf("%s\n", c_map->map[i]);
}

void	print_ray_struct(t_ray *c_ray, int only_ray)
{
	if (!only_ray)
	{
		printf("------MAP------\n");
		print_map_struct(c_ray->c_map);
		printf("------RAY------\n");
	}
	printf("player posx : %.2f\n", c_ray->player_posx);
	printf("player posy : %.2f\n", c_ray->player_posy);
	printf("player deltax : %.2f\n", c_ray->player_delx);
	printf("player deltay : %.2f\n", c_ray->player_dely);
	printf("player angle : %.2f\n", c_ray->player_angle);
}

static int		check_color(t_ray *c_ray, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0)
		return (0);
	if (map_x > c_ray->c_map->map_w - 1 || map_y > c_ray->c_map->map_h - 1)
		return (0);
	return (is_in_str("0NSEW", c_ray->c_map->map[map_y][map_x]));
}
