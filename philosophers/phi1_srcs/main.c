/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:04:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/08 19:00:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo1.h"

static int	check_die(int *die_lst, int nbr_phi)
{
	int	i;

	i = -1;
	while (++i < nbr_phi)
		if (die_lst[i] == 1)
			return (1);
	return (0);
}

static void	*exit_philo(t_philo *philo)
{
	if (!philo->config->die_lst[philo->id + 1])
		philo->config->die_lst[philo->id + 1] = 1;
	pthread_mutex_destroy(philo->right_fork);
	free(philo);
	return (NULL);
}

static void	*philo_loop(void *phi)
{
	t_philo *philo;
	long	value;

	philo = phi;
	while (!check_die(philo->config->die_lst, philo->config->nbr_phi) && !eat(philo))
	{
		value = display_status(philo, SLEEPING);
		if (value < 0)
			return (exit_philo(philo));
		if (value < 1000 * philo->config->time_sleep)
			usleep(value);
		else
			usleep(1000 * philo->config->time_sleep);
		if (display_status(philo, THINKING) < 0)
			return (exit_philo(philo));
	}
	return (exit_philo(philo));
}

static void	init_philosophers(int argc, char **argv)
{
	int				i;
	pthread_t		p_id;
	t_config		*config;
	t_philo			*current;
	pthread_mutex_t	*first;
	pthread_mutex_t	*last;

	config = malloc(sizeof(t_config));
	config->nbr_phi = phi_atoi(argv[1]);
	config->time_die = phi_atoi(argv[2]);
	config->time_eat = phi_atoi(argv[3]);
	config->time_sleep = phi_atoi(argv[4]);
	config->die_lst = malloc(sizeof(int) * config->nbr_phi);
	config->start_time = get_current();
	i = -1;
	while (++i < config->nbr_phi)
		config->die_lst[i] = 0;
	if (argc == 6)
		config->each_eat = phi_atoi(argv[5]);
	else
		config->each_eat = 0;
	i = -1;
	while (++i < config->nbr_phi)
	{
		current = malloc(sizeof(t_philo));
		current->id = i + 1;
		current->config = config;
		current->last_eat = config->start_time;
		if (i == 0)
		{
			first = malloc(sizeof(pthread_mutex_t));
			current->left_fork = first;
			pthread_mutex_init(current->left_fork, NULL);
			current->right_fork = malloc(sizeof(pthread_mutex_t));
			last = current->right_fork;
			pthread_mutex_init(current->right_fork, NULL);
		} else if (i == config->nbr_phi - 1)
		{
			current->left_fork = last;
			current->right_fork = first;
		}
		else
		{
			current->left_fork = last;
			current->right_fork = malloc(sizeof(pthread_mutex_t));
			last = current->right_fork;
			pthread_mutex_init(current->right_fork, NULL);
		}
		pthread_create(&p_id, NULL, philo_loop, (void *)current);
		pthread_detach(p_id);
	}
	while (!check_die(config->die_lst, config->nbr_phi))
		;
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