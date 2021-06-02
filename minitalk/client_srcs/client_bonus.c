/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:09:30 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/02 15:10:33 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_client	*g_client;

static void	init_client(void)
{
	g_client->c = 0;
	g_client->current_bit = 7;
	g_client->server_pid = 0;
	g_client->current_char = 0;
	g_client->sleep_status = -1;
}

static void	send_char(int signal)
{
	signal = (int)signal;
	if (((g_client->c >> g_client->current_bit) & 1) == 0)
		kill_exit(g_client->server_pid, SIGUSR1);
	else
		kill_exit(g_client->server_pid, SIGUSR2);
	if (g_client->sleep_status == -1)
		g_client->current_bit--;
	if (g_client->current_bit < 0)
	{
		g_client->current_bit = 7;
		g_client->current_char++;
		g_client->c = g_client->str[g_client->current_char];
		if (!(g_client->str[g_client->current_char]))
			exit(EXIT_SUCCESS);
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
			kill_exit(server_pid, SIGUSR2);
			str_len -= ft_pow(2, current_bit);
		}
		else
			kill_exit(server_pid, SIGUSR1);
		usleep(1000);
	}
}

static void	send_pid(int server_pid)
{
	int		client_pid;
	int		current_bit;

	current_bit = 32;
	client_pid = (int)getpid();
	while (--current_bit > -1)
	{
		if ((unsigned int)client_pid >= ft_pow(2, current_bit))
		{
			kill_exit(server_pid, SIGUSR2);
			client_pid -= ft_pow(2, current_bit);
		}
		else
			kill_exit(server_pid, SIGUSR1);
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	main_error(argc, argv);
	g_client = malloc(sizeof(t_client));
	init_client();
	server_pid = ft_atoi(argv[1]);
	g_client->server_pid = server_pid;
	g_client->str = argv[2];
	send_len(server_pid, argv);
	send_pid(server_pid);
	signal(SIGUSR1, send_char);
	i = -1;
	g_client->c = argv[2][0];
	send_char(0);
	while (1)
	{
		g_client->sleep_status = usleep(10000);
	}
	free(g_client);
	return (0);
}
