/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:35:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/25 13:33:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*free_and_return_s(char *to_free, char *to_ret)
{
	free(to_free);
	to_free = NULL;
	return (to_ret);
}

int		free_and_return_i(char *to_free, int to_ret)
{
	free(to_free);
	to_free = NULL;
	return (to_ret);
}