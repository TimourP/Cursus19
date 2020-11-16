/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:32:12 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 15:03:26 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int		i;
	char	*new_str;

	i = -1;
	new_str = (char *)str;
	c = (unsigned char)c;
	while (++i < len)
		new_str[i] = c;
	str = new_str;
	return (str);
}
