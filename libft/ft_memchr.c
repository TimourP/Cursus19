/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:38:36 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 20:08:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	size_t			i;

	new_s = (unsigned char *)s;
	i = -1;
	while (new_s[i] && i + 1 < n + 1)
	{
		if (new_s[i] == c)
			return (&new_s[i]);
	}
	return (0);
}
