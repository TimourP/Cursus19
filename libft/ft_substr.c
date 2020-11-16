/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:53:46 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 20:06:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		str_len;
	char	*str;
	int		to_add;

	i = -1;
	to_add = 0;
	str_len = ft_strlen(s) - start - 1;
	if (str_len > len)
		str_len = len;
	else
		to_add = to_add + 1;
	if (!(str = malloc(sizeof(char) * (str_len + 1))))
		return (NULL);
	while (s[++i + start] && --str_len + to_add > -1)
		str[i] = s[i + start];
	str[i] = 0;
	return (str);
}