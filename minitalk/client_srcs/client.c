/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:09:30 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/01 12:18:19 by tpetit           ###   ########.fr       */
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
		usleep(CLIENT_SLEEP);
		current_bit--;
	}
}

static void	main_error(int argc, char **argv)
{
	if (argc != 3)
		exit_message(ARGS_ERROR, EXIT_FAILURE);
}

static void	send_len(int server_pid, char **argv)
{
	int		str_len;
	int		current_bit;

	current_bit = 32;
	str_len = ft_strlen(argv[2]) + 1;
	while (--current_bit > -1)
	{
		if (str_len >= ft_pow(2, current_bit))
		{
			kill(server_pid, SIGUSR2);
			str_len -= ft_pow(2, current_bit);
		}
		else
			kill(server_pid, SIGUSR1);
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
	send_char('\n', server_pid);
	return (0);
}
