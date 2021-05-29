/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:09:30 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/29 11:19:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_char(char c, int server_pid)
{
	int	current_bit;

	current_bit = 7;
	while (current_bit > -1)
	{
		if (((c >> current_bit) & 1) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(10);
		current_bit--;
	}
	
}

int main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	server_pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		send_char(argv[2][i], server_pid);
	send_char('\n', server_pid);
	return (0);
}