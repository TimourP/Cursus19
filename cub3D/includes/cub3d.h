/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:21:11 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/12 12:29:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "cub3d_macro.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_image
{
	void		*mlx_img;
	char		*addr;
	char		*path;
	int			bpp;
	int			line_l;
	int			edian;
	int			width;
	int			height;
}				t_image;

typedef struct s_monster
{
	float	x;
	float	y;
	int		id;
	t_image	*img;
}				t_monster;

typedef struct s_monster_list
{
	t_monster				*content;
	struct s_monster_list	*next;
}				t_monster_list;

typedef struct s_sprite
{
	t_image		*img;
	float		distance;
	int			start_x;
	int			end_x;
	int			start_y;
	int			end_y;
	int			offset_x;
	int			offset_y;
	int			height;
	int			id;
	int			shot_count;
}				t_sprite;

typedef struct s_sprite_list
{
	t_sprite				*content;
	struct s_sprite_list	*next;
}				t_sprite_list;

typedef struct s_map
{
	int			screen_w;
	int			screen_h;
	int			map_w;
	int			map_h;
	t_image		*south_t;
	t_image		*north_t;
	t_image		*west_t;
	t_image		*east_t;
	t_image		*sprite_t;
	int			floor_t;
	int			ceiling_t;
	char		**map;
}				t_map;

typedef struct s_bonus_images
{
	t_image		*heart_t;
	t_image		*hunger_t;
	t_image		*empty_heart_t;
	t_image		*empty_hunger_t;
	t_image		*good_food;
	t_image		*good_health;
	t_image		*bad_health;
	t_image		*monster;
	t_image		*other_sprite_0;
	t_image		*other_sprite_1;
	t_image		*game_over;
}				t_bonus_images;

typedef struct s_ray
{
	t_map			*c_map;
	int				screen_w;
	int				screen_h;
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	char			*img_addr;
	int				img_bpp;
	int				img_line_l;
	int				img_edian;
	int				save;
	float			player_posx;
	float			player_posy;
	float			player_delx;
	float			player_dely;
	float			player_angle;
	int				go_forward;
	int				go_backward;
	int				go_left;
	int				go_right;
	int				turn_left;
	int				turn_right;
	int				look_offset;
	int				look_up;
	int				look_down;
	int				shoot;
	int				tic;
	long int		last_frame;
	long int		last_remove_life;
	long int		last_hit;
	float			player_speed;
	float			*all_distances;
	int				player_health;
	int				player_hunger;
	t_image			*sky;
	t_bonus_images	*bonus_images;
	t_sprite_list	*start_list;
	t_monster_list	*monster_list;
}				t_ray;

typedef struct s_ray_calc
{
	float		i;
	float		angle;
	float		d_disty;
	float		d_distx;
	float		s_disty;
	float		s_distx;
	float		final_dist;
	float		line_height;
	int			step_x;
	int			step_y;
	int			hit;
	int			mapx;
	int			mapy;
	int			side;
	int			x;
}				t_ray_calc;

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
int				free_on_error(t_map *c_map, int error_type);
int				check_parsing_error(t_map *c_map);
void			ft_spradd_back(t_sprite_list **alst, t_sprite_list *new);
void			ft_sprclear(t_sprite_list **lst);
t_sprite_list	*ft_sprnew(t_sprite *content);
void			ft_sprprint(t_sprite_list *lst);
void			exit_message(int message);

/*
** raycasting
*/

int				init_raycasting(t_ray *c_ray, t_map *c_map);
int				get_images(t_ray *c_ray, t_map *c_map);
void			set_hit(t_ray *c_ray, t_ray_calc *calc);
void			set_steps(t_ray *c_ray, t_ray_calc *calc);
int				get_side(t_ray_calc *calc);
float			get_texture_value(t_ray *c_ray, t_ray_calc *calc);
float			get_distance(t_ray *c_ray, float value, int *side);
float			get_absolute_distance(t_ray *c_ray, float angle);
int				get_line_height(t_ray *c_ray, float value, int *side,
					float *text_value);
int				get_all_sprites(t_ray *c_ray);
void			ft_sprsort(t_sprite_list *start);

/*
** moves
*/

int				key_press(int key, t_ray *c_ray);
int				key_release(int key, t_ray *c_ray);
int				get_next_frame(t_ray *c_ray);
int				exit_button(t_ray *c_ray);
int				quit_properly(t_ray *c_ray);

/*
** drawing
*/

void			draw_rectangle(t_ray *c_ray, const int xy[2],
					const int width_height[2], const int color);
void			draw_empty_rectangle(t_ray *c_ray, const int xy_wh[4],
					const int color, const int inner_width);
void			draw_line(t_ray *c_ray, int x_y_l[3],
					float angle, const int color);
int				draw_game(t_ray *c_ray);
void			draw_vertical_line(t_ray *c_ray, const int x,
					int length, const int color);
void			draw_vertical_texture(t_ray *c_ray, int x_len[2],
					t_image *texture, float y_value);
float			div_zero(float number1, float number2);
void			draw_pixel(t_ray *c_ray, int x, int y, int color);
void			get_pixel(t_image *image, int x,
					int y, int *color);
void			draw_sprite(t_ray *c_ray, t_sprite_list *c_list);

/*
**	SAVES
*/

void			create_xpm(t_ray *c_ray);
int				get_r(int color);
int				get_g(int color);
int				get_b(int color);

#endif
