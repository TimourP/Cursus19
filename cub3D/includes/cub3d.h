/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:21:11 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/25 16:38:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include "cub3d_macro.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_map
{
	int			screen_w;
	int			screen_h;
	int			map_w;
	int			map_h;
	char		*south_t;
	char		*north_t;
	char		*west_t;
	char		*east_t;
	char		*sprite_t;
	char		*floor_t;
	char		*ceiling_t;
	char		**map;
}				t_map;

typedef struct	s_ray
{
	t_map		c_map;
	int			screen_w;
	int			screen_h;
}				t_ray;

/*
** testing
*/

void			print_map_struct(t_map *c_map);
void			print_map(t_map *c_map);

/*
** parsing
*/

int				parse_map(t_map *c_map, char *map_path);
void			get_screen_resolution(t_map *c_map, char *line);
void			init_map_struct(t_map *c_map);
int				get_textures(t_map *c_map, char *line, char param);
int				get_colors(t_map *c_map, char *line, char param);
int				map_error(t_map *c_map);

/*
** utils
*/

char			*free_and_return_s(char *to_free, char *to_ret);
int				free_and_return_i(char *to_free, int to_ret);
void			free_split(char **to_free);
void			free_t_map(t_map *c_map);

/*
** raycasting
*/

int				init_raycasting(t_map *c_map);

#endif
