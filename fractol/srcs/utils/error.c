/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:24:57 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 10:44:15 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	print_settings(void)
{
	const char	settings[185] = "The fractol executable takes as parameter the name of a fractal before displaying with mlx a representation of this fractal. Valid parameters are : \n\t- julia\n\t- mandelbrot\n\t- other\n";
	write(1, settings, ft_strlen(settings));
}

void	exit_message(int message)
{
	if (message == ARG_ERROR)
	{
		write(1, "Error: args not found\n", 22);
		print_settings();
	}
	else if (message == FRACTAL_NAME_ERROR)
	{
		write(1, "Error: invalid fractal name\n", 28);
		print_settings();
	}
	exit(EXIT_FAILURE);
}
