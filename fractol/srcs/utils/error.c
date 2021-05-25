/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:24:57 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/25 21:13:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	print_settings(void)
{
	write(1, "The fractol executable takes as parameter the name", 50);
	write(1, " a fractal before displaying with mlx a representa", 50);
	write(1, "tion of this fractal.\nValid parameters are : \n\t- j", 50);
	write(1, "ulia\n\t- mandelbrot\n\t- other\n", 28);
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
	else if (message == MALLOC_ERROR)
		write(1, "Error: malloc fail\n", 19);
	else if (message == CLOSE_WINDOW)
	{
		write(1, "By!\n", 4);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

void	free_on_error(t_fract *fract, int message)
{
	mlx_destroy_image(fract->mlx_ptr, fract->mlx_img);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
	exit_message(message);
}
