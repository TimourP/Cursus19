/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:09:13 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/07 08:33:16 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int	j;
	int	value;
	int to_find_len;

	i = -1;
	to_find_len = (int)ft_strlen(to_find);
	while (++i < (int)len - to_find_len + 1)
	{
		value = 1;
		j = -1;
		while (++j < to_find_len)
			if (str[i + j] != to_find[j])
				value = 0;
		if (value)
			return ((char *)&str[i]);
	}
	return (NULL);
}
