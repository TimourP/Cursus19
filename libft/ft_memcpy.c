/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:52:57 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 15:22:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	int 	i;
	char	*new_dst;
	char	*new_src;
	char *test;

	new_dst = (char *)dst;
	new_src = (char *)src;
	test = (char *)dst;
	i = -1;
	while (++i < n)
		new_dst[i] = new_src[i];
	return (test);
}
