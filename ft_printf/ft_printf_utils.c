/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:52:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/06 12:16:24 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *join_back(char *malloced, char *add)
{
	int		i;
	char	*conc_str;

	if (malloced)
	{
		i = ft_strlen(malloced) + ft_strlen(add);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		i = -1;
		while (malloced[++i])
			conc_str[i] = malloced[i];
		i = -1;
		while (add[++i])
			conc_str[i + ft_strlen(malloced)] = add[i];
		free(malloced);
		return (conc_str);
	}
	return (add ? ft_strdup(add) : NULL);
}

char *join_front(char *malloced, char *add)
{
	int		i;
	char	*conc_str;

	if (malloced)
	{
		i = ft_strlen(malloced) + ft_strlen(add);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		i = -1;
		while (add[++i])
			conc_str[i] = add[i];
		i = -1;
		while (malloced[++i])
			conc_str[i + ft_strlen(add)] = malloced[i];
		free(malloced);
		return (conc_str);
	}
	return (add ? ft_strdup(add) : NULL);
}

char *string_with_length(char c, int length)
{
	int i;
	char *str;

	i = -1;
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (++i < length)
		str[i] = c;
	str[i] = 0;
	return (str);
}