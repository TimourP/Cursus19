/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:46:09 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 17:26:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char    *new_dst;
	char    *new_src;
	int     i;

	c = (unsigned char)c;
	new_src = (unsigned char*)src;
	new_dst = (unsigned char*)dst;
	i = -1;
	while (++i < n && new_src[i] != c)
		new_dst[i] = new_src[i];
	if (new_src[i] == c)
	{
		new_dst[i] = new_src[i];
		return (&new_dst[i + 1]);
	}
	return (0);
}
