/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:14:29 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/12 12:24:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*make_color_string(int rgb[3])
{
	char	*current_color;
	char	*color_string;
	int		i;

	if (!ft_malloc(&color_string, sizeof(char) * 7))
		return (NULL);
	ft_bzero(color_string, 7);
	i = -1;
	while (++i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			exit_message(RGB_OVERFLOW);
		current_color = ft_itoa_base(rgb[i], 16, "0123456789abcdef");
		if (!current_color)
			return (free_and_return_s(color_string, NULL));
		color_string[i * 2] = current_color[0];
		color_string[1 + i * 2] = current_color[1];
		if (color_string[1 + i * 2] == 0)
		{
			color_string[1 + i * 2] = color_string[i * 2];
			color_string[i * 2] = '0';
		}
		free(current_color);
	}
	return (color_string);
}

void	get_screen_resolution(t_map *c_map, char *line)
{
	int	i;

	while (*line && *line == ' ')
		line++;
	i = 1;
	c_map->screen_w = ft_atoi(&line[i]);
	i += (int)number_len(c_map->screen_w, 10) + 1;
	c_map->screen_h = ft_atoi(&line[i]);
}

static void	set_correct_string(t_map *c_map, char *str, char param)
{
	if (param == 'n' && !c_map->north_t->path)
		c_map->north_t->path = str;
	else if (param == 's' && !c_map->south_t->path)
		c_map->south_t->path = str;
	else if (param == 'e' && !c_map->east_t->path)
		c_map->east_t->path = str;
	else if (param == 'w' && !c_map->west_t->path)
		c_map->west_t->path = str;
	else if (param == 'S' && !c_map->sprite_t->path)
		c_map->sprite_t->path = str;
	else if (param == 'c')
	{
		c_map->ceiling_t = ft_atoi_base(str, "0123456789abcdef");
		free(str);
	}
	else if (param == 'f')
	{
		c_map->floor_t = ft_atoi_base(str, "0123456789abcdef");
		free(str);
	}
	else
		exit_message(MULTIPLE_SAME_LINES);
}

int	get_colors(t_map *c_map, char *line, char param)
{
	char	*trim_line;
	char	**split_line;
	int		rgb[3];

	while (*line && ft_is_wspace(*line))
		line++;
	trim_line = ft_strtrim(&line[2], " \t");
	if (!trim_line)
		return (0);
	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	split_line = ft_split(trim_line, ',');
	if (split_line[0])
		rgb[0] = ft_atoi(split_line[0]);
	if (split_line[1])
		rgb[1] = ft_atoi(split_line[1]);
	if (split_line[2])
		rgb[2] = ft_atoi(split_line[2]);
	set_correct_string(c_map, make_color_string(rgb), param);
	free_split(split_line);
	free(trim_line);
	return (1);
}

int	get_textures(t_map *c_map, char *line, char param)
{
	char	*trim_line;

	while (*line && ft_is_wspace(*line))
		line++;
	trim_line = ft_strtrim(&line[2], " \t");
	if (!trim_line)
		return (0);
	set_correct_string(c_map, trim_line, param);
	return (1);
}
