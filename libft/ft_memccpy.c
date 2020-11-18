/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:46:09 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/18 11:20:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

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