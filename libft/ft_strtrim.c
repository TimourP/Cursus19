/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:19:26 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 19:45:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		set_include(char c, char const *set)
{
	int i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

int		count_to_trim(char const *s1, char const *set)
{
	int i;
	int count;
	const int s1_len = (const int)ft_strlen(s1);

	count = 0;
	i = -1;
	while (s1[++i] && set_include(s1[i], set))
		count++;
	i = 0;
	while (++i < s1_len && set_include(s1[s1_len - i], set))
		count++;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		to_trim;
	int		i;
	char	*trim_str;
	int		j;

	to_trim = count_to_trim(s1, set);
	if (to_trim > (const int)ft_strlen(s1))
		to_trim = (const int)ft_strlen(s1);
	if (!(trim_str = malloc(sizeof(char) * (ft_strlen(s1) - to_trim + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
	{
		if (!set_include(s1[j], set))
		{
			trim_str[i] = s1[j];
			i++;
		}
	}
	trim_str[ft_strlen(s1) - to_trim] = 0;
	return (trim_str);
}