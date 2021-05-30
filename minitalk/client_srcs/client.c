/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:09:30 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/30 09:42:34 by tpetit           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	int		server_pid;
	int		i;
	int		str_len;
	int		current_bit;

	main_error(argc, argv);
	current_bit = 32;
	server_pid = ft_atoi(argv[1]);
	str_len = (ft_strlen(argv[2]) + 1) * 8;
	printf("%d\n", str_len);
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
	i = -1;
	while (argv[2][++i])
		send_char(argv[2][i], server_pid);
	send_char('\n', server_pid);
	return (0);
}