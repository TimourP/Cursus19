/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:46:51 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/23 10:11:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*conc_str;

	if (s1)
	{
		i = ft_strlen(s1) + ft_strlen(s2) + 1;
		if (!(conc_str = malloc(sizeof(char) * i)))
			return (NULL);
		conc_str[i - 1] = 0;
		i = -1;
		while (s1[++i])
			conc_str[i] = s1[i];
		i = -1;
		while (s2[++i])
			conc_str[i + ft_strlen(s1)] = s2[i];
		return (conc_str);
	}
	return (0);
}
