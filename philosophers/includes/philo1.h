/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:50:17 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/09 12:04:39 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO1_H
# define PHILO1_H

# include "./philosophers.h"

/*
** ACTIONS
*/

int		eat(t_philo *philo);
void	init_philosophers(int argc, char **argv);
void	*philo_loop(void *phi);

#endif