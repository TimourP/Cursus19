/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:59:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 18:36:58 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define MALLOC_ERROR 0
# define NBR_ARGS_ERROR 1
# define ARGS_ERROR 2

/*
**	UTILS
*/

void	exit_message(int message);
int		check_argv(int argc, char **argv);
int		phi_atoi(const char *str);

#endif