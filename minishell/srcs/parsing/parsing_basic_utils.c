/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_basic_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:22:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/12 13:54:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_in_str(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

char	*strdup_until(const char *str, char *c_lst)
{
	int		i;
	char	*dest;

	i = -1;
	while (str[++i] && !is_in_str(c_lst, str[i]))
		;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (str[++i] && !is_in_str(c_lst, str[i]))
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

char	*strdup_until_c(const char *str, char c)
{
	int		i;
	char	*dest;

	i = -1;
	while (str[++i] && str[i] != c)
		;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != c)
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}

char	*parse_join(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*conc_str;

	len = my_strlen(s1) + my_strlen(s2);
	conc_str = malloc(sizeof(char) * (len + 1));
	if (!conc_str)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	conc_str[len] = 0;
	i = -1;
	len = my_strlen(s1);
	if (len > 0)
		while (++i < len)
			conc_str[i] = s1[i];
	i = -1;
	if (my_strlen(s2) > 0)
		while (s2[++i])
			conc_str[i + len] = s2[i];
	free(s1);
	free(s2);
	return (conc_str);
}
