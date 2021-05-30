/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/30 09:53:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_server *g_server;

static char	*ft_join_one(char *str, char c)
{
	int i;
	char *new_str;
	int len;

	if (!str)
	{
		new_str = malloc(sizeof(char) * 2);
		new_str[0] = c;
		new_str[1] = 0;
		return (new_str);
	}
	i = -1;
	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 2));
	while (++i < len)
		new_str[i] = str[i];
	new_str[i] = c;
	new_str[i + 1] = 0;
	free(str);
	return (new_str);
}

void decode_binary(int signal)
{
	g_server->end_transmission = 0;
	if (g_server->len_count < 32)
	{
		if (signal == SIGUSR2)
			g_server->total_char += ft_pow(2, 31 - g_server->len_count);
		g_server->len_count++;
		return ;
	}
	if (signal == SIGUSR2)
		g_server->current_char += ft_pow(2, 7 - g_server->current_bit);
	g_server->current_bit++;
	g_server->total_bits++;
	if (g_server->current_bit >= 8)
	{
		g_server->current_str = ft_join_one(g_server->current_str, g_server->current_char);
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
	g_server->total_bits = 0;
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
		usleep(CLIENT_SLEEP * 4);
		if (g_server->end_transmission == 1 && g_server->current_str)
		{
			if (g_server->total_bits != g_server->total_char)
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
			g_server->total_bits = 0;
		}
	}
	return (0);
}