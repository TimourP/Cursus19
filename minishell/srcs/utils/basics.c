/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:53:46 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/18 15:52:08 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	my_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*my_strcpy(char *src, char *dst)
{
	size_t	i;

	if (!src || !dst)
		return ((void *)0);
	i = my_strlen(src);
	dst[i--] = '\0';
	while (i + 1)
	{
		dst[i] = src[i];
		i--;
	}
	return (dst);
}

char	*my_strncpy(char *src, char *dst, int n)
{
	int	i;

	if (!src || !dst)
		return ((void *)0);
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*my_strjoin(char *str, char *add)
{
	char	*new;
	size_t	size;

	size = my_strlen(str);
	new = malloc(sizeof(*new) * size + my_strlen(add) + 1);
	if (!new)
		return ((void *)0);
	new = my_strcpy(str, new);
	my_strcpy(add, new + size);
	return (new);
}

char	*my_strdup(char *str)
{
	char	*new;

	if (!str)
		return ((void *)0);
	new = malloc(sizeof(*new) * (my_strlen(str) + 1));
	if (!new)
		return ((void *)0);
	new = my_strcpy(str, new);
	return (new);
}
