/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:24:57 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 18:37:33 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	print_settings(void)
{
	printf("The fractol executable takes as parameter the name");
	printf(" a fractal before displaying with mlx a representation");
	printf(" of this fractal.\nValid parameters are : \n");
	if (BONUS)
		printf("\t- Julia\n\t- Mandelbrot\n\t- Beryl\n");
	else
		printf("\t- Julia\n\t- Mandelbrot\n");
}

void	exit_message(int message)
{
	if (message == ARG_ERROR)
	{
		printf("Error: args not found\n");
		print_settings();
	}
	else if (message == FRACTAL_NAME_ERROR)
	{
		printf("Error: invalid fractal name\n");
		print_settings();
	}
	else if (message == MALLOC_ERROR)
		printf("Error: malloc fail\n");
	else if (message == CLOSE_WINDOW)
	{
		printf("Bye!\n");
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

void	free_on_error(t_fract *fract, int message)
{
	mlx_destroy_image(fract->mlx_ptr, fract->mlx_img->mlx_img);
	mlx_destroy_window(fract->mlx_ptr, fract->mlx_win);
	free(fract->mlx_img);
	exit_message(message);
}
