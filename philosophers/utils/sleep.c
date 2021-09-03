/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:04:43 by tpetit            #+#    #+#             */
/*   Updated: 2021/09/03 16:05:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_sleep(long ms)
{
	const long	time_start = get_current();

	while (get_current() - time_start < ms * 1000)
		usleep(80);
}
