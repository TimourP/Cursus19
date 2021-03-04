/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:36:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/04 10:36:53 by tpetit           ###   ########.fr       */
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
	printf("player posx : %d\n", c_ray->player_posx);
	printf("player posy : %d\n", c_ray->player_posy);
	printf("player deltax : %d\n", c_ray->player_delx);
	printf("player deltay : %d\n", c_ray->player_dely);
	printf("player angle : %f\n", c_ray->player_angle);
}

static int		check_color(t_ray *c_ray, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0)
		return (0);
	if (map_x > c_ray->c_map->map_w - 1 || map_y > c_ray->c_map->map_h - 1)
		return (0);
	return (is_in_str("0NSEW", c_ray->c_map->map[map_y][map_x]));
}

void	d_map(t_ray *c_ray)
{
	int 		i;
	int 		j;
	int			xy[2];
	const int	w_h[2] = {MINI_SQUARE, MINI_SQUARE};

	i = -1;
	while (++ i < c_ray->c_map->map_h)
	{
		j = -1;
		while (++j < c_ray->c_map->map_w)
		{
			xy[0] = j * MINI_SQUARE;
			xy[1] = i * MINI_SQUARE;
			draw_rectangle(c_ray, xy, w_h, is_in_str("0NSEW", c_ray->c_map->map[i][j]) ? COLOR_WHITE : COLOR_RED);
		}
	}
}

void	drawRay(t_ray *c_ray)
{
	int posx = c_ray->player_posx;
	int posy = c_ray->player_posy;
	float dirx = -1;
	float diry = 0;
	float planex = 0;
	float planey = 0.66;
	int i;

	i = -1;
	while (++i < c_ray->screen_w)
	{
		float camerax = 2 * i / (c_ray->screen_w - 1);
		float rayDirx = dirx + planex * camerax;
		float raydiry = diry + planey + camerax;
	}
	
}

int	minimap_ray(t_ray *c_ray)
{
	//int	xy[2] = {0, 0};
	//int	pl_xy[2] = {c_ray->player_posx - MINI_SQUARE/2, c_ray->player_posy - MINI_SQUARE/2};
	//int	w_h[2] = {MINI_SQUARE, MINI_SQUARE};
	//int	w_h_m[2] = {c_ray->screen_w, c_ray->screen_h};

	//draw_rectangle(c_ray, xy, w_h_m, 0x00000000);
	//d_map(c_ray);
	//draw_rectangle(c_ray, pl_xy, w_h, COLOR_BLACK);
	//mlx_put_image_to_window(c_ray->mlx_ptr, c_ray->mlx_win, c_ray->mlx_img, 0, 0);
	drawRay(c_ray);
	return (0);
} 