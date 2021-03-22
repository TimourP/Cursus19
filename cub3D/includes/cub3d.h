/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:21:11 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/22 14:39:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
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
	t_map		*c_map;
	int			screen_w;
	int			screen_h;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	char		*img_addr;
	int			img_bpp;
	int			img_line_l;
	int			img_edian;
	float		player_posx;
	float		player_posy;
	float		player_delx;
	float		player_dely;
	float		player_angle;
	int			go_forward;
	int			go_backward;
	int			go_left;
	int			go_right;
	int			turn_left;
	int			turn_right;
}				t_ray;

/*
** testing
*/

void			print_map_struct(t_map *c_map);
void			print_map(t_map *c_map);
void			print_ray_struct(t_ray *c_ray, int only_ray);
int				minimap_ray(t_ray *c_ray);

/*
** parsing
*/

int				parse_map(t_map *c_map, char *map_path);
void			get_screen_resolution(t_map *c_map, char *line);
void			init_map_struct(t_map *c_map);
int				get_textures(t_map *c_map, char *line, char param);
int				get_colors(t_map *c_map, char *line, char param);
int				map_error(t_map *c_map);
t_list			*list_from_file(char *map_path);

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

int				init_raycasting(t_ray *c_ray, t_map *c_map);

/*
** moves
*/

int				key_press(int key, t_ray *c_ray);
int				key_release(int key, t_ray *c_ray);
int				get_next_frame(t_ray *c_ray);
int				exit_button(t_ray *c_ray);

/*
** drawing
*/

void			draw_rectangle(t_ray *c_ray, const int xy[2],
				const int width_height[2], const int color);
void			draw_empty_rectangle(t_ray *c_ray, const int xy_wh[4],
				const int color, const int inner_width);
void			draw_circle(t_ray *c_ray, const int xy[2],
				const int radius, const int color);
void			draw_rotate_rectangle(t_ray *c_ray, const int xy_wh[4],
				const int color, const float angle);
void			draw_player(t_ray *c_ray, const int xy_wh[4],
				const int color, float angle);
int				minimap(t_ray *c_ray);

#endif
