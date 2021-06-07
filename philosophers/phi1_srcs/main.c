/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:04:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 19:37:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	init_philosophers(int argc, char **argv)
{
	int			ndest[5];
	int			i;
	pthread_t	p_id;

	ndest[0] = phi_atoi(argv[1]);
	ndest[1] = phi_atoi(argv[2]);
	ndest[2] = phi_atoi(argv[3]);
	ndest[3] = phi_atoi(argv[4]);
	if (argc == 6)
		ndest[4] = phi_atoi(argv[5]);
	else
		ndest[4] = 0;
	i = -1;
	p_id = malloc(sizeof(pthread_t));
	while (++i < ndest[0])
	{
		/* code */
	}
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		exit_message(NBR_ARGS_ERROR);
	if (!check_argv(argc, argv))
		exit_message(ARGS_ERROR);
	init_philosophers(argc, argv);
	return (0);
}