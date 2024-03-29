/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:07:49 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 14:02:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_malloc(char **to_malloc, size_t size)
{
	*to_malloc = malloc(size);
	if (!*to_malloc)
		return (0);
	return (1);
}

int	ft_int_malloc(int **to_malloc, size_t size)
{
	*to_malloc = malloc(size);
	if (!*to_malloc)
		return (0);
	return (1);
}

int	big_m(char ***to_malloc, size_t size)
{
	*to_malloc = malloc(size);
	if (!*to_malloc)
		return (0);
	return (1);
}
