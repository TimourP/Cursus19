/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/03 14:46:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_server	*g_server;

static void	malloc_server(void)
{
	g_server->len_count++;
	g_server->current_str = malloc(sizeof(char) * g_server->total_char + 1);
	if (!g_server->current_str)
	{
		free(g_server);
		exit_message(MALLOC_ERROR, EXIT_FAILURE);
	}
	g_server->current_str[g_server->total_char] = 0;
}

static void	decode_binary(int signal)
{
	if (g_server->len_count < 32)
	{
		if (signal == SIGUSR2)
			g_server->total_char += ft_pow(2, 31 - g_server->len_count);
		g_server->len_count++;
		return ;
	}
	if (g_server->len_count == 32)
		malloc_server();
	if (signal == SIGUSR2)
		g_server->current_char += ft_pow(2, 7 - g_server->current_bit);
	g_server->current_bit++;
	if (g_server->current_bit >= 8)
	{
		if (g_server->char_count < (int)g_server->total_char)
			g_server->current_str[g_server->char_count]
				= g_server->current_char;
		g_server->char_count++;
		g_server->current_char = 0;
		g_server->current_bit = 0;
	}
}

static void	init_server(void)
{
	g_server->current_bit = 0;
	g_server->current_char = 0;
	g_server->char_count = 0;
	g_server->len_count = 0;
	g_server->total_char = 0;
	g_server->client_pid = 0;
	g_server->current_str = NULL;
}

static void	wait_end_error(void)
{
	put_str("Error");
	while (usleep(10000) != 0)
		;
}

int	main(void)
{
	int	sleep_value;

	g_server = malloc(sizeof(t_server));
	if (!g_server)
		exit_message(MALLOC_ERROR, EXIT_FAILURE);
	init_server();
	g_server->server_pid = getpid();
	ft_putnbr(g_server->server_pid);
	if (signal(SIGUSR1, decode_binary) == SIG_ERR
		|| signal(SIGUSR2, decode_binary) == SIG_ERR)
		return (1);
	while (1)
	{
		sleep_value = usleep(CLIENT_SLEEP * 10);
		if (sleep_value == 0 && g_server->current_str)
		{
			if (g_server->char_count != (int)g_server->total_char)
				wait_end_error();
			else
				put_str(g_server->current_str);
			free(g_server->current_str);
			init_server();
		}
	}
	return (0);
}
