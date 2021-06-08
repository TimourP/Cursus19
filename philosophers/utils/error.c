/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:06:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/08 16:26:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	exit_message(int message)
{
	if (message == NBR_ARGS_ERROR)
	{
		printf("Error: invalid number of arguments.\n");
		printf("Usage: ./philo_* [number_of_philosopher] [time_to_die] [time_to_eat] [time_to_sleep] *[number_of_time_each_philosophers_must_eat]\n");
	}
	if (message == ARGS_ERROR)
		printf("Error: args have to be positive integer.\n");
}

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (phi_atoi(argv[i]) < 0)
			return (0);
	return (1);
}
