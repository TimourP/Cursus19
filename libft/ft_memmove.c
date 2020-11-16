/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:44:01 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 18:01:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	i = -1;
	new_src = (unsigned char *)src;
	new_dst = (unsigned char *)dst;
	if (new_src < new_dst)
		while (++i < len)
			new_dst[len - i - 1 ] = new_src[len - i - 1];
	else
		while (++i < len)
			new_dst[i] = new_src[i];
	return (dst);
}