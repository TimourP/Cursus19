/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:04:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/31 18:15:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*philo_loop(void *phi)
{
	t_philo		*philo;
	t_philo_lst	*phi_lst;
	long		value;

	phi_lst = phi;
	philo = phi_lst->philo;
	if (philo->config->nbr_phi % 2 && philo->id % 2)
		usleep((philo->config->time_eat / 2.0) * 1000);
	while (!philo->config->one_die)
	{
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
