/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:52:57 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/18 11:33:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t		i;
	char		*new_dst;
	char		*new_src;

	if (!dst && !src)
		return (dst);
	new_dst = (char *)dst;
	new_src = (char *)src;
	i = -1;
	while (++i < n)
		new_dst[i] = new_src[i];
	return (dst);
}
