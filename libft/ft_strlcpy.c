/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:40:04 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 15:02:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t			srcsize;
	unsigned int	i;

	srcsize = ft_strlen(src);
	if (srcsize + 1 < size)
	{
		i = -1;
		while (++i < srcsize + 1)
			dest[i] = src[i];
	}
	else if (size)
	{
		i = -1;
		while (++i < size - 1)
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (srcsize);
}
