/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:53:46 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/23 10:12:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	size_t	str_len;
	char	*str;
	int		to_add;

	if (s)
	{
		i = -1;
		to_add = 0;
		str_len = ft_strlen(s) - start - 1;
		if (str_len > len)
			str_len = len;
		else
			to_add = to_add + 1;
		if (start >= (unsigned int)str_len)
			str_len = 0;
		if (!(str = malloc(sizeof(char) * (str_len + 1))))
			return (NULL);
		while (s[++i + start] && (size_t)i < str_len + to_add)
			str[i] = s[i + start];
		str[i] = 0;
		return (str);
	}
	return (0);
}
