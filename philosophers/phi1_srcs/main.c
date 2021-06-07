/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:04:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 18:31:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		exit_message(NBR_ARGS_ERROR);
	if (!check_argv(argc, argv))
		exit_message(ARGS_ERROR);
	return (0);
}