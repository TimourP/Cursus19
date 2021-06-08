/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:48:56 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/08 16:17:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo1.h"

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	display_status(philo->id, TAKE_FORK);
	pthread_mutex_lock(philo->right_fork);
	display_status(philo->id, TAKE_FORK);
	display_status(philo->id, EATING);
	usleep(1000 * philo->config->time_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}
