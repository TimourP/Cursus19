/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:33:57 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/03 14:13:24 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	init_server(t_server *g_server)
{
	g_server->current_bit = 0;
	g_server->current_char = 0;
	g_server->char_count = 0;
	g_server->len_count = 0;
	g_server->total_char = 0;
	g_server->client_pid = 0;
	g_server->yet_print = 0;
	g_server->error = 0;
	g_server->current_str = NULL;
}

void	main_loop(t_server *g_server)
{
	if (g_server->error)
		put_str("Server ok");
	if (!g_server->error && (g_server->char_count == g_server->total_char
			|| g_server->total_char == 0))
		put_str(g_server->current_str);
	else if (g_server->char_count != g_server->total_char && !g_server->error)
		put_str("ERROR: client probably kill before the end of the message");
	free(g_server->current_str);
	init_server(g_server);
}
