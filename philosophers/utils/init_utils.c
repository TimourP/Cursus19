/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:13:08 by tpetit            #+#    #+#             */
/*   Updated: 2021/09/03 11:55:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_config(int argc, char **argv, t_config *config)
{
	config->nbr_phi = phi_atoi(argv[1]);
	config->time_die = phi_atoi(argv[2]);
	config->time_eat = phi_atoi(argv[3]);
	config->time_sleep = phi_atoi(argv[4]);
	config->start_time = get_current();
	config->each_eat = 0;
	config->one_die = 0;
	config->phi_died = malloc(sizeof(pthread_mutex_t));
	if (!config->phi_died)
		return (0);
	if (pthread_mutex_init(config->phi_died, NULL))
		return (0);
	if (argc == 6)
		config->each_eat = phi_atoi(argv[5]);
	return (1);
}

static int	init_forks(t_philo_lst *start, t_philo *current,
	t_config *config, int i)
{
	static pthread_mutex_t	*last;

	current->right_fork = malloc(sizeof(pthread_mutex_t));
	if (!current->right_fork)
		return (0);
	if (pthread_mutex_init(current->right_fork, NULL))
		return (0);
	if (config->nbr_phi == 1)
		current->left_fork = current->right_fork;
	else if (i == 0)
		last = current->right_fork;
	else if (i == config->nbr_phi - 1)
	{
		current->left_fork = last;
		start->philo->left_fork = current->right_fork;
	}
	else
	{
		current->left_fork = last;
		last = current->right_fork;
	}
	return (1);
}

t_philo_lst	*return_free(t_philo_lst *start, t_philo *current)
{
	philo_lst_clear(&start);
	if (current)
	{
		if (current->right_fork)
			pthread_mutex_destroy(current->right_fork);
		free(current->right_fork);
		free(current);
	}
	return (NULL);
}

t_philo_lst	*init_philos(t_config *config)
{
	int				i;
	t_philo			*current;
	t_philo_lst		*start;
	t_philo_lst		*new;

	i = -1;
	start = NULL;
	while (++i < config->nbr_phi)
	{
		current = malloc(sizeof(t_philo));
		if (!current)
			return (return_free(start, current));
		current->id = i + 1;
		current->eat_count = 0;
		current->config = config;
		current->last_eat = config->start_time;
		current->last_since_eat_time = 0;
		if (!init_forks(start, current, config, i))
			return (return_free(start, current));
		new = philo_lst_new(current);
		if (!new)
			return (return_free(start, current));
		philo_lst_add_back(&start, new);
	}
	return (start);
}
