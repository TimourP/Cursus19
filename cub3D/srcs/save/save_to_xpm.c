/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:28:43 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/04 10:23:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_r(int color)
{
	return (color & (0xFF << 16));
}

int	get_g(int color)
{
	return (color & (0xFF << 8));
}

int	get_b(int color)
{
	return (color & 0xFF);
}

static void	get_image_pixel(t_ray *c_ray, int x, int y, int *color)
{
	char	*dst;

	dst = c_ray->img_addr + (y * c_ray->img_line_l + x * (c_ray->img_bpp / 8));
	*color = *(unsigned int *)dst;
}

static void	write_color(int fd, int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(get_r(color));
	g = (unsigned char)(get_g(color));
	b = (unsigned char)(get_b(color));
	write(fd, &r, sizeof(r));
	write(fd, &g, sizeof(g));
	write(fd, &b, sizeof(b));
}

void	create_xpm(t_ray *c_ray)
{
	int	i;
	int	j;
	int	fd;
	int	color;

	fd = open("save.xpm", O_CREAT | O_WRONLY | O_TRUNC, 0x777);
	i = -1;
	while (++i < c_ray->screen_h)
	{
		j = -1;
		while (++j < c_ray->screen_w)
		{
			get_image_pixel(c_ray, 0, 0, &color);
			write_color(fd, color);
		}
	}
	close(fd);
}