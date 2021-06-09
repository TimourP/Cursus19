/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:03:22 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/09 16:07:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo1.h"

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

void	init_philosophers(int argc, char **argv)
{
	int				i;
	pthread_t		p_id;
	t_config		*config;
	t_philo			*current;
	t_philo_lst		*start;
	t_philo_lst		*new;

	config = malloc(sizeof(t_config));
	start = NULL;
	if (!init_config(argc, argv, config))
		return ;
	i = -1;
	while (++i < config->nbr_phi)
	{
		current = malloc(sizeof(t_philo));
		current->id = i + 1;
		current->config = config;
		current->last_eat = config->start_time;
		init_forks(current, config, i);
		new = philo_lst_new(current);
		philo_lst_add_back(&start, new);
		pthread_create(&p_id, NULL, philo_loop, (void *)current);
		new->philo->p_id = p_id;
	}
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
