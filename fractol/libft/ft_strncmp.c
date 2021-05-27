/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:24:23 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 13:13:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (*s1 && *s1 == ' ')
		s1++;
	while (1)
	{
		if ((!*s1 && !*s2) || !n)
			return (0);
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
	}
}
