/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_bmp_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:28:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/06 15:56:23 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
