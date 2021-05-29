/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:06:34 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/29 11:17:39 by tpetit           ###   ########.fr       */
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
	int		current_bit;
	int		end_transmission;
	char	current_char;
	int		char_count;
}				t_server;

#endif