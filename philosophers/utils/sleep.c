/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:04:43 by tpetit            #+#    #+#             */
/*   Updated: 2021/09/03 16:33:23 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_sleep(long ms)
{
	const long	time_start = get_current();

	if (ms <= 0)
		return ;
	while (get_current() - time_start < ms * 1000)
		usleep(80);
}

void	ft_sleep_not_null(long ms)
{
	const long	time_start = get_current();

	if (ms <= 0)
		ms = 1;
	while (get_current() - time_start < ms * 1000)
		usleep(80);
}
