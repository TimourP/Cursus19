/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:48:56 by tpetit            #+#    #+#             */
/*   Updated: 2021/09/03 16:50:56 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	take_fork_first_left(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (display_status(philo, TAKE_FORK) < 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	return (0);
}

static int	take_fork_first_right(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (display_status(philo, TAKE_FORK) < 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_lock(philo->left_fork);
	return (0);
}

static int	dispatch_fork(t_philo *philo)
{
	if (philo->id % 2 || philo->config->nbr_phi % 2)
	{
		if (take_fork_first_left(philo))
			return (1);
	}
	else
	{
		if (take_fork_first_right(philo))
			return (1);
	}
	return (0);
}

int	eat(t_philo *philo)
{
	if (dispatch_fork(philo))
		return (1);
	if (display_status(philo, TAKE_FORK) < 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	if (display_status(philo, EATING) < 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	philo->eat_count++;
	if (philo->config->time_eat < philo->config->time_die)
		ft_sleep(philo->config->time_eat, philo->config);
	else
		ft_sleep(philo->config->time_die, philo->config);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}
