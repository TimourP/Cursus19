/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:04:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/09/03 16:54:24 by tpetit           ###   ########.fr       */
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
		ft_sleep_not_null((philo->config->time_eat / 2.0), philo->config);
	while (!philo->config->one_die)
	{
		if (eat(philo))
			return (NULL);
		display_status(philo, SLEEPING);
		ft_sleep(philo->config->time_sleep, philo->config);
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
