/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:09:30 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/01 14:34:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_char(char c, int server_pid)
{
	int	current_bit;
	int	sleep_status;

	current_bit = 7;
	while (current_bit > -1)
	{
		if (((c >> current_bit) & 1) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		sleep_status = usleep(50000);
		if (sleep_status == -1)
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
	str_len = ft_strlen(argv[2]);
	while (--current_bit > -1)
	{
		if (str_len >= ft_pow(2, current_bit))
		{
			kill(server_pid, SIGUSR2);
			str_len -= ft_pow(2, current_bit);
		}
		else
			kill(server_pid, SIGUSR1);
		usleep(1000);
	}
}

static void	send_pid(int server_pid)
{
	int		client_pid;
	int		current_bit;

	current_bit = 32;
	client_pid = (int)getpid();
	printf("Pid: %d\n", client_pid);
	while (--current_bit > -1)
	{
		if (client_pid >= ft_pow(2, current_bit))
		{
			kill(server_pid, SIGUSR2);
			client_pid -= ft_pow(2, current_bit);
		}
		else
			kill(server_pid, SIGUSR1);
		usleep(1000);
	}
}

static void	test(int test)
{
	;
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	main_error(argc, argv);
	server_pid = ft_atoi(argv[1]);
	send_len(server_pid, argv);
	send_pid(server_pid);
	signal(SIGUSR1, test);
	i = -1;
	while (argv[2][++i])
		send_char(argv[2][i], server_pid);
	return (0);
}
