/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/01 10:29:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_server *g_server;

static char	*ft_join_one(char c)
{
	int i;
	char *new_str;
	int len;

	if (!g_server->current_str)
	{
		new_str = malloc(sizeof(char) * 2);
		new_str[0] = c;
		new_str[1] = 0;
		return (new_str);
	}
	i = -1;
	len = ft_strlen(g_server->current_str);
	new_str = malloc(sizeof(char) * (len + 2));
	while (++i < len)
		new_str[i] = g_server->current_str[i];
	new_str[i] = c;
	new_str[i + 1] = 0;
	free(g_server->current_str);
	g_server->current_str = NULL;
	return (new_str);
}

void decode_binary(int signal)
{
	char *pending;

	g_server->end_transmission = 0;
	if (g_server->len_count < 32)
	{
		if (signal == SIGUSR2)
			g_server->total_char += ft_pow(2, 31 - g_server->len_count);
		g_server->len_count++;
		return ;
	}
	if (g_server->len_count == 32)
	{
		g_server->len_count++;
		g_server->current_str = malloc(sizeof(char) * g_server->total_char + 1);
		g_server->current_str[g_server->total_char] = 0;
	}
	if (signal == SIGUSR2)
		g_server->current_char += ft_pow(2, 7 - g_server->current_bit);
	g_server->current_bit++;
	if (g_server->current_bit >= 8)
	{
		if (g_server->char_count < g_server->total_char)
			g_server->current_str[g_server->char_count] = g_server->current_char;
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
	g_server->len_count = 0;
	g_server->total_char = 0;
	g_server->current_str = NULL;
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
		usleep(CLIENT_SLEEP * 10);
		if (g_server->end_transmission == 1 && g_server->current_str)
		{
			if (g_server->char_count != g_server->total_char)
				printf("Error\n");
			else
				printf("%s", g_server->current_str);
			free(g_server->current_str);
			g_server->current_str = NULL;
			g_server->len_count = 0;
			g_server->total_char = 0;
			g_server->current_bit = 0;
			g_server->current_char = 0;
			g_server->char_count = 0;
		}
	}
	return (0);
}