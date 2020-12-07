/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:19:54 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/07 08:56:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*dest;
	size_t		i;

	if (!(dest = malloc(count * size)))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = -1;
	while (++i < count * size)
		dest[i] = 0;
	return ((void*)dest);
}
