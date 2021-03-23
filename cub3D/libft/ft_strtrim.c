/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:19:26 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 10:04:26 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_include(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

static int	count_to_trim(char const *s1, char const *set, int *to)
{
	int			i;
	int			count;
	const int	s1_len = (const int)ft_strlen(s1);

	count = 0;
	i = -1;
	while (s1[++i] && set_include(s1[i], set))
		count++;
	i = 0;
	*to = 0;
	while (++i < s1_len && set_include(s1[s1_len - i], set))
	{
		count++;
		*to = *to + 1;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		to_trim;
	int		i;
	char	*trim_str;
	size_t	j;
	int		to;

	if (s1)
	{
		to_trim = count_to_trim(s1, set, &to);
		if (to_trim > (const int)ft_strlen(s1))
			to_trim = (const int)ft_strlen(s1);
		trim_str = malloc(sizeof(char) * (ft_strlen(s1) - to_trim + 1));
		if (!trim_str)
			return (NULL);
		trim_str[ft_strlen(s1) - to_trim] = 0;
		i = 0;
		j = to_trim - to - 1;
		while (++j < ft_strlen(s1) - to)
		{
			trim_str[i] = s1[j];
			i++;
		}
		return (trim_str);
	}
	return (NULL);
}
