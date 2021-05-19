/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:05:29 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 10:24:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	draw_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}