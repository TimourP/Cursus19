/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:34 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/03 14:02:12 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/libft.h"

typedef struct s_client
{
	int		c;
	int		server_pid;
	int		current_bit;
	int		current_char;
	int		sleep_status;
	char	*str;
}				t_client;

typedef struct s_server
{
	int				current_bit;
	int				char_count;
	int				len_count;
	int				client_pid;
	int				server_pid;
	int				total_bits;
	int				yet_print;
	int				error;
	unsigned int	total_char;
	char			current_char;
	char			*current_str;
}				t_server;

# define ARGS_ERROR 0
# define INVALID_PID 1
# define STR_PID 2
# define CLIENT_SLEEP 100

/*
** UTILS
*/

void			exit_message(int message, int status);
unsigned int	ft_pow(int base, int exp);
void			main_error(int argc, char **argv);
void			put_str(const char *s);
void			kill_exit(int pid, int signal, t_client *g_client);
void			main_loop(t_server *g_server);

#endif