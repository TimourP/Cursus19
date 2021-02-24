/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:21:11 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/24 20:00:19 by tpetit           ###   ########.fr       */
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
	int test;
}				t_map;

/*
** parsing
*/

int				parse_map(t_map *c_map, char *map_path);

#endif
