/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:38:36 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/03 10:59:24 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	size_t			i;

	new_s = (unsigned char *)s;
	c = (unsigned char)c;
	i = -1;
	while ((int)++i < (int)n)
	{
		if (new_s[i] == c)
			return ((void *)&new_s[i]);
	}
	return (NULL);
}
