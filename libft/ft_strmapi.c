/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:18:37 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 18:31:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				str_len;
	char			*dest;

	i = -1;
	str_len = ft_strlen(s);
	if (!(dest = malloc(sizeof(char) * (str_len + 1))))
		return (NULL);
	while (++i < str_len)
		dest[i] = f(i, s[i]);
	dest[i] = 0;
	return (dest);
}
