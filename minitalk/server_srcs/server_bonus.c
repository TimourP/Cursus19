/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/02 13:58:16 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_server	*g_server;

static void	init_server(void)
{
	g_server->current_bit = 0;
	g_server->current_char = 0;
	g_server->char_count = 0;
	g_server->len_count = 0;
	g_server->total_char = 0;
	g_server->client_pid = 0;
	g_server->total_bits = 0;
	g_server->yet_print = 0;
	g_server->current_str = NULL;
}

static void	malloc_server(void)
{
	g_server->len_count++;
	if (g_server->client_pid < g_server->server_pid)
	{
		exit(EXIT_SUCCESS);
	}
	g_server->current_str = malloc(sizeof(char) * g_server->total_char + 1);
	g_server->current_str[g_server->total_char] = 0;
}

static int	get_len_pid(int signal)
{
	if (g_server->len_count < 32)
	{
		if (signal == SIGUSR2)
			g_server->total_char += ft_pow(2, 31 - g_server->len_count);
		g_server->len_count++;
		return (1);
	}
	if (g_server->len_count < 64)
	{
		if (signal == SIGUSR2)
			g_server->client_pid += ft_pow(2, 63 - g_server->len_count);
		g_server->len_count++;
		return (1);
	}
	return (0);
}

static void	decode_binary(int signal)
{
	if (get_len_pid(signal))
		return ;
	if (g_server->len_count == 64)
		malloc_server();
	if (signal == SIGUSR2)
		g_server->current_char += ft_pow(2, 7 - g_server->current_bit);
	g_server->current_bit++;
	g_server->total_bits++;
	if (g_server->current_bit >= 8)
	{
		if (g_server->char_count < g_server->total_char)
			g_server->current_str[g_server->char_count]
				= g_server->current_char;
		g_server->char_count++;
		g_server->current_char = 0;
		g_server->current_bit = 0;
	}
	kill(g_server->client_pid, SIGUSR1);
	if (!g_server->yet_print && g_server->total_char == g_server->char_count)
	{
		put_str(g_server->current_str);
		free(g_server->current_str);
		init_server();
	}
}

int	main(void)
{
	int	sleep_value;

	sleep_value = -1;
	g_server = malloc(sizeof(t_server));
	init_server();
	g_server->server_pid = getpid();
	ft_putnbr(g_server->server_pid);
	if (signal(SIGUSR1, decode_binary) == SIG_ERR
		|| signal(SIGUSR2, decode_binary) == SIG_ERR)
		return (1);
	while (1)
	{
		sleep_value = sleep(1);
		if (sleep_value == 0 && g_server->current_str)
		{
			if (!g_server->yet_print)
				put_str(g_server->current_str);
			free(g_server->current_str);
			init_server();
		}
	}
	return (0);
}
