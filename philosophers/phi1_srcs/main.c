/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:04:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/09 16:11:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo1.h"

void	*philo_loop(void *phi)
{
	t_philo	*philo;
	long	value;
	int		die;

	philo = phi;
	pthread_mutex_lock(philo->config->phi_died);
	die = philo->config->one_die;
	pthread_mutex_unlock(philo->config->phi_died);
	while (!die && eat(philo))
	{
		value = display_status(philo, SLEEPING);
		if (value < 0)
			return (NULL);
		if (value < 1000 * philo->config->time_sleep)
			usleep(value);
		else
			usleep(1000 * philo->config->time_sleep);
		if (display_status(philo, THINKING) < 0)
			return (NULL);
		pthread_mutex_lock(philo->config->phi_died);
		die = philo->config->one_die;
		pthread_mutex_unlock(philo->config->phi_died);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		exit_message(NBR_ARGS_ERROR);
	else if (!check_argv(argc, argv))
		exit_message(ARGS_ERROR);
	else
		init_philosophers(argc, argv);
	return (0);
}
