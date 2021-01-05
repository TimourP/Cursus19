/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:49:07 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/05 14:13:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

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

void	ft_strcpy_from(char *dst, char *src, char c)
{
	int i;
	int j;
	int start;

	i = -1;
	j = -1;
	start = 0;
	while (src[++i])
	{
		if (start)
			dst[++j] = src[i];
		else if (src[i] == c)
			start = 1;
	}
	dst[j + 1] = 0;
}

char	*ft_strcpy(char *dest, char *src)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (src[++i])
	{
		count++;
	}
	i = -1;
	while (i++ < count)
	{
		dest[i] = src[i];
	}
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
		i = ft_strlen(s1) + ft_strlen_until(s2, c);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		i = -1;
		while (s1[++i])
			conc_str[i] = s1[i];
		i = -1;
		while (s2[++i] && s2[i] != c)
			conc_str[i + ft_strlen(s1)] = s2[i];
		free(s1);
		return (conc_str);
	}
	return (ft_strdup_until(s2, c));
}