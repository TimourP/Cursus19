/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:24:23 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/24 14:01:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_in_str(char *str, char c)
{
	int i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

size_t	ft_strlen_until(char *str, char c)
{
	size_t i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] && str[i] != c)
		;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*conc_str;

	len = ft_strlen_until(s1, 0) + ft_strlen_until(s2, 0);
	if (!(conc_str = malloc(sizeof(char) * (len + 1))))
	{
		free(s1);
		return (NULL);
	}
	conc_str[len] = 0;
	i = -1;
	len = ft_strlen_until(s1, 0);
	if (len > 0)
		while (++i < len)
			conc_str[i] = s1[i];
	i = -1;
	if (ft_strlen_until(s2, 0) > 0)
		while (s2[++i])
			conc_str[i + len] = s2[i];
	free(s1);
	return (conc_str);
}

char	*ft_strdup_until(char *src, char c)
{
	int		i;
	char	*dest;

	if (!src)
		return (NULL);
	i = ft_strlen_until(src, c);
	if (!(dest = (char*)malloc((i + 1) * sizeof(char))))
	{
		free(src);
		return (NULL);
	}
	dest[i] = 0;
	i = -1;
	while (src[++i] && src[i] != c)
		dest[i] = src[i];
	return (dest);
}

char	*ft_strdup_from(char *str, int from)
{
	int		i;
	char	*dest;

	if (!str)
		return (NULL);
	if (!is_in_str(str, '\n'))
	{
		free(str);
		return (NULL);
	}
	i = ft_strlen_until(str + from, 0);
	if (!(dest = malloc((i + 1) * sizeof(char))))
	{
		free(str);
		return (NULL);
	}
	dest[i] = 0;
	i = -1;
	while (str[++i + from])
		dest[i] = str[i + from];
	free(str);
	return (dest);
}
