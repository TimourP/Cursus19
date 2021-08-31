/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:04:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/31 16:52:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	can_eat(t_philo_lst *phi_lst, t_philo *philo)
{
	t_philo_lst *tmp;

	if (phi_lst->next && philo->eat_count > phi_lst->next->philo->eat_count)
		return (0);
	if (phi_lst->prev && philo->eat_count > phi_lst->prev->philo->eat_count)
		return (0);
	if (!phi_lst->next) {
		tmp = phi_lst;
		while (tmp->prev)
			tmp = tmp->prev;
		if (philo->eat_count > tmp->philo->eat_count)
			return (0);
	}
	if (!phi_lst->prev) {
		tmp = phi_lst;
		while (tmp->next)
			tmp = tmp->next;
		if (philo->eat_count > tmp->philo->eat_count)
			return (0);
	}
	return (1);
}

void	*philo_loop(void *phi)
{
	t_philo	*philo;
	t_philo_lst *phi_lst;
	long	value;

	phi_lst = phi;
	philo = phi_lst->philo;
	while (!philo->config->one_die)
	{
		if (!can_eat(phi_lst, philo))
			continue ;
		if (eat(philo))
			return (NULL);
		value = display_status(philo, SLEEPING);
		if (value < 0)
			return (NULL);
		if (value < 1000 * philo->config->time_sleep)
			usleep(value);
		else
			usleep(1000 * philo->config->time_sleep);
		if (display_status(philo, THINKING) < 0)
			return (NULL);
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
