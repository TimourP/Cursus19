/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:28:43 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 11:41:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static void		put_bpm_header(int height, int stride, int fd)
{
	int				file_size;
	unsigned char	file_header[14];
	int				i;

	i = -1;
	while (++i < 14)
		file_header[i] = 0;
	file_size = 14 + 40 + (stride * height);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	write(fd, file_header, sizeof(file_header));
}

static void		put_bpm_infos(int height, int width, int fd)
{
	unsigned char	info_header[40];
	int				i;

	i = -1;
	while (++i < 40)
		info_header[i] = 0;
	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(width);
	info_header[5] = (unsigned char)(width >> 8);
	info_header[6] = (unsigned char)(width >> 16);
	info_header[7] = (unsigned char)(width >> 24);
	info_header[8] = (unsigned char)(height);
	info_header[9] = (unsigned char)(height >> 8);
	info_header[10] = (unsigned char)(height >> 16);
	info_header[11] = (unsigned char)(height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(3 * 8);
	write(fd, info_header, sizeof(info_header));
}

int	get_r(int color)
{
	if (color == 16777215)
		return (255);
	return ((color & (0xFF << 16)) / 255 / 255);
}

int	get_g(int color)
{
	if (color == 16777215)
		return (255);
	return ((color & (0xFF << 8)) / 255);
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
	write(fd, &b, sizeof(b));
	write(fd, &g, sizeof(g));
	write(fd, &r, sizeof(r));
}

void	create_xpm(t_ray *c_ray)
{
	int	i;
	int	j;
	int	fd;
	int	color;

	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777);
	put_bpm_header(c_ray->screen_h, (c_ray->screen_w * 3)
				+ ((4 - (c_ray->screen_w * 3) % 4) % 4), fd);
	put_bpm_infos(c_ray->screen_h, c_ray->screen_w, fd);
	i = -1;
	while (++i < c_ray->screen_h)
	{
		j = -1;
		while (++j < c_ray->screen_w)
		{
			get_image_pixel(c_ray, j, c_ray->screen_h - i - 1, &color);
			write_color(fd, color);
		}
	}
	close(fd);
}