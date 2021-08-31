/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:03:22 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/31 14:17:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	init_config(int argc, char **argv, t_config *config)
{
	config->nbr_phi = phi_atoi(argv[1]);
	config->time_die = phi_atoi(argv[2]);
	config->time_eat = phi_atoi(argv[3]);
	config->time_sleep = phi_atoi(argv[4]);
	config->start_time = get_current();
	config->each_eat = 0;
	config->one_die = 0;
	config->phi_died = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(config->phi_died, NULL);
	if (argc == 6)
		config->each_eat = phi_atoi(argv[5]);
	return (1);
}

static int	init_forks(t_philo *current, t_config *config, int i)
{
	static pthread_mutex_t	*first;
	static pthread_mutex_t	*last;

	if (i == 0)
	{
		first = malloc(sizeof(pthread_mutex_t));
		current->left_fork = first;
		pthread_mutex_init(current->left_fork, NULL);
		current->right_fork = malloc(sizeof(pthread_mutex_t));
		last = current->right_fork;
		pthread_mutex_init(current->right_fork, NULL);
	}
	else if (i == config->nbr_phi - 1)
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
	return (1);
}

static t_philo_lst	*init_philos(t_config *config)
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
		current->id = i + 1;
		current->config = config;
		current->last_eat = config->start_time;
		current->last_since_eat_time = 0;
		init_forks(current, config, i);
		new = philo_lst_new(current);
		philo_lst_add_back(&start, new);
	}
	return (start);
}

static int	main_loop_check(t_philo_lst	*start, t_config *config)
{
	t_philo_lst		*new;

	new = start;
	while (!config->one_die && new)
	{
		if (new->philo->last_since_eat_time > config->time_die * 1000
			|| (get_current() - new->philo->last_eat) > config->time_die * 1000)
		{
			pthread_mutex_lock(config->phi_died);
			if (!config->one_die)
			{
				config->one_die = 1;
				printf("%-13ld %d %s\n", get_current() / 1000
					- config->start_time / 1000, new->philo->id, "died");
			}
			pthread_mutex_unlock(config->phi_died);
			break ;
		}
		new = new->next;
		if (!new)
			new = start;
	}
	return (0);
}

static void	free_stop_philos(t_philo_lst *start, t_config *config)
{
	t_philo_lst		*new;

	new = start;
	while (new)
	{
		pthread_join(new->philo->p_id, NULL);
		pthread_mutex_unlock(new->philo->right_fork);
		pthread_mutex_unlock(new->philo->left_fork);
		new = new->next;
	}
	philo_lst_clear(&start);
	pthread_mutex_destroy(config->phi_died);
	free(config->phi_died);
	free(config);
}

void	init_philosophers(int argc, char **argv)
{
	t_config		*config;
	t_philo_lst		*start;
	t_philo_lst		*new;

	config = malloc(sizeof(t_config));
	if (!init_config(argc, argv, config))
		return ;
	start = init_philos(config);
	if (!start)
		return ;
	new = start;
	config->start_time = get_current();
	while (new)
	{
		new->philo->last_eat = config->start_time;
		pthread_create(&new->philo->p_id, NULL, philo_loop, (void *)new->philo);
		new = new->next;
	}
	main_loop_check(start, config);
	free_stop_philos(start, config);
}
