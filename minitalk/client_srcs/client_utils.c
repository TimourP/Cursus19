/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:24:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/01 16:25:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	main_error(int argc, char **argv)
{
	if (argc != 3)
		exit_message(ARGS_ERROR, EXIT_FAILURE);
}
