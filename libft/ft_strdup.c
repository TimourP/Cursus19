/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:55:24 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/02 12:19:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	i = -1;
	while (str[++i])
		;
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
