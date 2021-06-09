/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:26:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/09 10:45:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	check_die(int *die_lst, int nbr_phi)
{
	int	i;

	i = -1;
	while (++i < nbr_phi)
		if (die_lst[i] == 1)
			return (1);
	return (0);
}

long	get_current(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000000 + current_time.tv_usec);
}

long	display_status(t_philo *philo, int status)
{
	const char		*status_txt[] = {"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};
	long			c_time;

	pthread_mutex_lock(philo->config->phi_died);
	if (check_die(philo->config->die_lst, philo->config->nbr_phi))
	{
		pthread_mutex_unlock(philo->config->phi_died);
		return (-1);
	}
	c_time = get_current();
	if (status == EATING)
		philo->last_eat = c_time;
	else if (c_time - philo->last_eat > philo->config->time_die
		* 1000 && status != DIED)
	{
		printf("%ld %d %s\n", get_current() / 1000, philo->id, "died");
		philo->config->die_lst[philo->id - 1] = 1;
		pthread_mutex_unlock(philo->config->phi_died);
		return (-1);
	}
	printf("%ld %d %s\n", get_current() / 1000, philo->id, status_txt[status]);
	pthread_mutex_unlock(philo->config->phi_died);
	return (philo->config->time_die * 1000 - (c_time - philo->last_eat));
}
