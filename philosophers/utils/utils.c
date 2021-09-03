/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 16:26:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/09/03 15:28:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	get_current(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000000 + current_time.tv_usec);
}

static int	get_current_lock(t_philo *philo, long *c_time)
{
	pthread_mutex_lock(philo->config->phi_died);
	if (philo->config->one_die)
	{
		pthread_mutex_unlock(philo->config->phi_died);
		return (-1);
	}
	*c_time = get_current();
	return (0);
}

int	ft_strlen(const char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	philo_print(t_philo *philo, const char *status)
{
	const long	timestamp = get_current() / 1000
			- philo->config->start_time / 1000;

	ft_putnbr(timestamp);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	if (status == EATING)
		write(1, " " EATING "\n", ft_strlen(EATING) + 2);
	else if (status == SLEEPING)
		write(1, " " SLEEPING "\n", ft_strlen(SLEEPING) + 2);
	else if (status == THINKING)
		write(1, " " THINKING "\n", ft_strlen(THINKING) + 2);
	else if (status == TAKE_FORK)
		write(1, " " TAKE_FORK "\n", ft_strlen(TAKE_FORK) + 2);
	else if (status == DIED)
		write(1, " " DIED "\n", ft_strlen(DIED) + 2);
}

long	display_status(t_philo *philo, char *status)
{
	long			c_time;

	if (get_current_lock(philo, &c_time) < 0)
		return (-1);
	if (status == EATING)
	{
		philo->last_since_eat_time = c_time - philo->last_eat;
		philo->last_eat = c_time;
	}
	else if ((c_time - philo->last_eat) / 1000 >= philo->config->time_die)
	{
		philo_print(philo, DIED);
		philo->config->one_die = 1;
		pthread_mutex_unlock(philo->config->phi_died);
		return (-1);
	}
	philo_print(philo, status);
	pthread_mutex_unlock(philo->config->phi_died);
	return (philo->config->time_die - (c_time - philo->last_eat) / 1000);
}
