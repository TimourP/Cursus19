/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:56:50 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/18 11:20:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	i = -1;
	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	while (++i < n - 1 && ns1[i] == ns2[i])
		;
	return (ns1[i] - ns2[i]);
}
