/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:24:04 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/12 12:25:17 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_until(const char *str, char c)
{
	size_t i;

	i = -1;
	while (str[++i] && str[i] != c)
		;
	return (i);
}

char	*ft_strdup_until(char *src, char c)
{
	int		i;
	char	*dest;

	i = -1;
	while (src[++i] && src[i] != c)
		;
	if (!(dest = malloc((i + 1) * sizeof(char))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = -1;
	while (src[++i] && src[i] != c)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_from(char *src, char c)
{
	int		i;
	int		len;
	int		start;
	char	*dest;

	start = src ? ft_strlen_until(src, c) + 1 : 0;
	len = src ? ft_strlen_until(src, 0) - start : 0;
	if (!(dest = malloc((len + 1) * sizeof(char))))
	{
		errno = ENOMEM;
		free(src);
		return (NULL);
	}
	i = -1;
	while (++i < len)
		dest[i] = src[i + start];
	dest[i] = 0;
	free(src);
	return (dest);
}

int		ft_is_in_str(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

char	*ft_strjoin_until(char *s1, char *s2, char c)
{
	int			i;
	char		*conc_str;

	if (s1)
	{
		i = ft_strlen_until(s1, 0) + ft_strlen_until(s2, c);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		i = -1;
		while (s1[++i])
			conc_str[i] = s1[i];
		i = -1;
		while (s2[++i] && s2[i] != c)
			conc_str[i + ft_strlen_until(s1, 0)] = s2[i];
		free(s1);
		return (conc_str);
	}
	return (ft_strdup_until(s2, c));
}
