/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:45:31 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/03 13:54:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	exit_message(int message, int status)
{
	if (message == ARGS_ERROR)
		write(1, "ERROR: Incorrect number of arguments, required 2.\n", 50);
	else if (message == STR_PID)
		write(1, "ERROR: PID value has to be a number bigger than 0.\n", 51);
	else if (message == INVALID_PID)
		write(1, "ERROR: Invalid PID.\n", 20);
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

void	kill_exit(int pid, int signal, t_client *g_client)
{
	if (kill(pid, signal) == -1)
	{
		if (g_client)
			free(g_client);
		exit_message(INVALID_PID, EXIT_FAILURE);
	}
}
