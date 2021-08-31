/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:59:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/31 16:29:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

# define MALLOC_ERROR 0
# define NBR_ARGS_ERROR 1
# define ARGS_ERROR 2

# define TAKE_FORK 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DIED 4

typedef struct s_config
{
	int				nbr_phi;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				each_eat;
	int				one_die;
	long			start_time;
	pthread_mutex_t	*phi_died;
}				t_config;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_eat;
	long			last_since_eat_time;
	pthread_t		p_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_config		*config;
}				t_philo;

typedef struct s_philo_lst
{
	t_philo				*philo;
	struct s_philo_lst	*next;
	struct s_philo_lst	*prev;
}				t_philo_lst;

/*
**	UTILS
*/

void		exit_message(int message);
int			check_argv(int argc, char **argv);
int			phi_atoi(const char *str);
long		display_status(t_philo *philo, int status);
long		get_current(void);

/*
**	LST
*/

void		philo_lst_clear(t_philo_lst **lst);
t_philo_lst	*philo_lst_new(t_philo *content);
void		philo_lst_add_back(t_philo_lst **alst, t_philo_lst *new);

/*
** SRCS
*/

int			eat(t_philo *philo);
void		init_philosophers(int argc, char **argv);
void		*philo_loop(void *phi);

#endif