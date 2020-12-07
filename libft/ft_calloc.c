/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:19:54 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/03 10:57:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*dest;
	size_t		i;

	if (!(dest = malloc(count * size)))
		return (NULL);
	i = -1;
	while (++i < count * size)
		dest[i] = 0;
	return ((void*)dest);
}
