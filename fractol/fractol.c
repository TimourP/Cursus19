/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:14:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 10:50:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void main_error(int argc, char **argv)
{
	const char	*fractals_list[3] = {"julia", "mandelbrot", "other"};
	int			in_list;
	int			i;

	in_list = 0;
	i = 0;
	if (argc != 2)
		exit_message(ARG_ERROR);
	while (++i <= 3)
		if (ft_strncmp(argv[1], fractals_list[i - 1], ft_strlen(argv[1])) == 0)
			in_list = i;
	if (!in_list)
		exit_message(FRACTAL_NAME_ERROR);
}

int main(int argc, char **argv)
{
	t_fract *fract;

	fract = malloc(sizeof(t_fract));
	if (!fract)
		exit_message(MALLOC_ERROR);
	main_error(argc, argv);
	init_mlx(fract);
}