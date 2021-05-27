/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:14:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 13:08:31 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	main_error(int argc, char **argv, t_fract *fract)
{
	const char	*fractals_list[3] = {"julia", "mandelbrot", "beryl"};
	int			in_list;
	int			i;

	in_list = 0;
	i = 0;
	if (argc != 2)
		exit_message(ARG_ERROR);
	while (++i <= 2 + BONUS)
		if (ft_strncmp(argv[1], fractals_list[i - 1],
				ft_strlen(fractals_list[i - 1])) == 0)
			in_list = i;
	if (!in_list)
		exit_message(FRACTAL_NAME_ERROR);
	fract->id = in_list - 1;
}

int	main(int argc, char **argv)
{
	t_fract	*fract;

	fract = malloc(sizeof(t_fract));
	if (!fract)
		exit_message(MALLOC_ERROR);
	main_error(argc, argv, fract);
	init_mlx(fract);
}
