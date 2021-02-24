/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:22:14 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/24 19:40:26 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main_error(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map c_map;

	if (!main_error(argc, argv))
		return (-1);
	if (!parse_map(&c_map, argv[1]))
		return (-1);
}