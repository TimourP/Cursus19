/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/29 11:18:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_server *g_server;

void decode_binary(int signal)
{
	const int	values[8] = {128, 64, 32, 16, 8, 4, 2, 1};

	g_server->end_transmission = 0;
	if (signal == SIGUSR2)
		g_server->current_char += values[g_server->current_bit];
	g_server->current_bit++;
	if (g_server->current_bit >= 8)
	{
		write(1, &g_server->current_char, 1);
		g_server->char_count++;
		g_server->current_char = 0;
		g_server->current_bit = 0;
	}
}

static void	init_server(void)
{
	g_server->current_bit = 0;
	g_server->current_char = 0;
	g_server->end_transmission = 1;
	g_server->char_count = 0;
}

int main(void)
{
	g_server = malloc(sizeof(t_server));
	init_server();
	printf("%d\n", getpid());
	if (signal(SIGUSR1, decode_binary) == SIG_ERR)
		return (1);
	if (signal(SIGUSR2, decode_binary) == SIG_ERR)
		return (1);
	while (1)
	{
		g_server->end_transmission = 1;
		usleep(10000);
		if (g_server->end_transmission == 1 && (g_server->current_char != 0 || g_server->current_bit != 0))
		{
			printf("\n\n%d\n\n", g_server->char_count);
			if (g_server->current_char != '\n')
				write(1, "\nMessage probably corrupt, to avoid this kind of error please increase the client sleep time between each messages\n", 115);
			g_server->current_bit = 0;
			g_server->current_char = 0;
			g_server->char_count = 0;
		}
	}
	return (0);
}