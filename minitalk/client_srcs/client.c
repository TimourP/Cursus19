/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:09:30 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/03 13:55:41 by tpetit           ###   ########.fr       */
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
			kill_exit(server_pid, SIGUSR1, NULL);
		else
			kill_exit(server_pid, SIGUSR2, NULL);
		usleep(CLIENT_SLEEP);
		current_bit--;
	}
}

static void	send_len(int server_pid, char **argv)
{
	int		str_len;
	int		current_bit;

	current_bit = 32;
	str_len = ft_strlen(argv[2]);
	while (--current_bit > -1)
	{
		if ((unsigned int)str_len >= ft_pow(2, current_bit))
		{
			kill_exit(server_pid, SIGUSR2, NULL);
			str_len -= ft_pow(2, current_bit);
		}
		else
			kill_exit(server_pid, SIGUSR1, NULL);
		usleep(CLIENT_SLEEP);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	main_error(argc, argv);
	server_pid = ft_atoi(argv[1]);
	send_len(server_pid, argv);
	i = -1;
	while (argv[2][++i])
		send_char(argv[2][i], server_pid);
	return (0);
}
