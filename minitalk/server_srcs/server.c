/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/28 15:08:48 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void decode_binary(int signal)
{
	static int	current_bits;
	static char	current_char;
	const int	values[8] = {128, 64, 32, 16, 8, 4, 2, 1};

	if (signal == SIGUSR2)
		current_char += values[current_bits];
	current_bits++;
	if (current_bits >= 8)
	{
		write(1, &current_char, 1);
		current_char = 0;
		current_bits = 0;
	}
}

int main(void)
{
	static char	current_char;

	printf("%d\n", getpid());
	signal(SIGUSR1, decode_binary);
	signal(SIGUSR2, decode_binary);
	while (1)
		pause();
	return (0);
}