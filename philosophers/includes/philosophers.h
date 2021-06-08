/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:59:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/08 18:46:03 by tpetit           ###   ########.fr       */
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
	int		nbr_phi;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		each_eat;
	int		*die_lst;
	long	start_time;
}				t_config;

typedef struct s_philo
{
	int				id;
	long			last_eat;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_config		*config;
}				t_philo;

/*
**	UTILS
*/

void	exit_message(int message);
int		check_argv(int argc, char **argv);
int		phi_atoi(const char *str);
long	display_status(t_philo *philo, int status);
long	get_current(void);

#endif