/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:34 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/01 11:44:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../libft/libft.h"

# include <stdio.h>

typedef struct s_server
{
	int				current_bit;
	int				char_count;
	int				len_count;
	unsigned int	total_char;
	char			current_char;
	char			*current_str;
}				t_server;

# define ARGS_ERROR 0
# define CLIENT_SLEEP 50

/*
** UTILS
*/

void			exit_message(int message, int status);
unsigned int	ft_pow(int base, int exp);

#endif