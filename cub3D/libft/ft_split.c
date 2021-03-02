/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:45:58 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/02 10:28:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (++i < (int)ft_strlen(str))
	{
		if (str[i] == c && str[i - 1] != c)
			count++;
	}
	if (str[i - 1] != c)
		count++;
	return (count);
}

static int	*calc_len(char const *str, char c, int count)
{
	int i;
	int j;
	int curr_word;
	int *count_array;

	i = -1;
	curr_word = 0;
	if (!(count_array = malloc(sizeof(int) * count)))
		return (0);
	while (str[++i] && curr_word < count)
	{
		j = -1;
		while (str[++j + i] != c && str[j + i])
			;
		if (j)
		{
			count_array[curr_word] = j;
			curr_word++;
			i = i + j;
		}
	}
	return (count_array);
}

char		**free_all(char **tab, int index)
{
	int i;

	i = -1;
	while (++i < index)
		free(tab[i]);
	free(tab);
	return (0);
}

static char	**split_main(char const *str, int count, int *count_array, char c)
{
	int		ij[2];
	int		curr_word;
	char	**final_array;
	char	*p_str;

	if (!(final_array = malloc(sizeof(char*) * (count + 1))))
		return (0);
	ij[0] = -1;
	curr_word = 0;
	while (str[++ij[0]])
	{
		if (str[ij[0]] != c)
		{
			ij[1] = -1;
			if (!(p_str = malloc(sizeof(char) * (count_array[curr_word] + 1))))
				return (free_all(final_array, curr_word));
			while (++ij[1] < count_array[curr_word])
				p_str[ij[1]] = str[ij[1] + ij[0]];
			p_str[count_array[curr_word]] = 0;
			final_array[curr_word] = p_str;
			curr_word++;
			ij[0] += ij[1] - 1;
		}
	}
	return (final_array);
}

char		**ft_split(char const *str, char c)
{
	int			word_count;
	int			*count_array;
	char		**final_array;

	if (!str)
		return (NULL);
	if (!str[0])
	{
		if (!(final_array = malloc(sizeof(char*) * 1)))
			return (NULL);
		final_array[0] = 0;
		return (final_array);
	}
	word_count = count_words(str, c);
	if (!(count_array = calc_len(str, c, word_count)))
		return (NULL);
	if (!(final_array = split_main(str, word_count, count_array, c)))
	{
		free(count_array);
		return (NULL);
	}
	final_array[word_count] = 0;
	free(count_array);
	return (final_array);
}
