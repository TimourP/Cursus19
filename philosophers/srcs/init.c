/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:03:22 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/19 08:49:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	main_loop_check_end(t_philo_lst **new, t_philo_lst *start,
	int *min_eat, t_config *config)
{
	if ((*new)->philo->eat_count < *min_eat || *min_eat == 0)
		*min_eat = (*new)->philo->eat_count;
	*new = (*new)->next;
	if (!(*new))
	{
		if (*min_eat >= config->each_eat && config->each_eat != 0)
		{
			config->one_die = 1;
		}
		*min_eat = 0;
		(*new) = start;
	}
}

static int	main_loop_check(t_philo_lst	*start, t_config *config)
{
	t_philo_lst		*new;
	int				min_eat;

	new = start;
	min_eat = 0;
	while (!config->one_die && new)
	{
		if ((new->philo->last_since_eat_time) / 1000 > config->time_die
			|| (get_current() - new->philo->last_eat) / 1000 > config->time_die)
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
		main_loop_check_end(&new, start, &min_eat, config);
	}
	return (0);
}

void	free_stop_philos(t_philo_lst *start, t_config *config)
{
	t_philo_lst		*new;

	new = start;
	while (new)
	{
		pthread_mutex_unlock(new->philo->right_fork);
		pthread_join(new->philo->p_id, NULL);
		new = new->next;
	}
	philo_lst_clear(&start);
	pthread_mutex_destroy(config->phi_died);
	free(config->phi_died);
	free(config);
}

void	free_config(t_config *conf, int destroy_mutex)
{
	if (destroy_mutex)
		pthread_mutex_destroy(conf->phi_died);
	free(conf->phi_died);
	free(conf);
}

void	init_philosophers(int argc, char **argv)
{
	t_config		*config;
	t_philo_lst		*start;
	t_philo_lst		*new;

	config = malloc(sizeof(t_config));
	if (!config)
		return ;
	if (!init_config(argc, argv, config))
		return (free_config(config, 0));
	start = init_philos(config);
	if (!start)
		return (free_config(config, 1));
	new = start;
	config->start_time = get_current();
	while (new)
	{
		new->philo->last_eat = config->start_time;
		if (pthread_create(&new->philo->p_id, NULL, philo_loop, (void *)new))
			return (exit_if_create_error(start, config));
		new = new->next;
	}
	main_loop_check(start, config);
	free_stop_philos(start, config);
}
