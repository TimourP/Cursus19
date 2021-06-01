/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:45:31 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/01 11:49:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	exit_message(int message, int status)
{
	if (message == ARGS_ERROR)
		write(1, "ERROR: Incorrect number of arguments, required 2.\n", 50);
	exit(status);
}

unsigned int	ft_pow(int base, int exp)
{
	int	i;
	int	val;

	i = -1;
	val = 1;
	while (++i < exp)
		val *= base;
	return (val);
}
