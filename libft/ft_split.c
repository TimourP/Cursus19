/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:45:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 18:52:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int		count_words(char *str, char c)
{
	int i;
	int inword;
	int count;

	i = -1;
	inword = 0;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
		{
			if (inword)
			{
				inword = 0;
				count++;
			}
		}
		else if (!inword)
			inword = 1;
	}
	if (i > 0 && str[i - 1] != c)
		count++;
	return (count);
}

void	add_word(int *ijcw, char *str, char **dest, char c)
{
	char *currdst;

	ijcw[1] = -1;
	if (str[ijcw[0] + 1] == 0)
	{
		ijcw[2]++;
		ijcw[0]++;
	}
	currdst = malloc(sizeof(char) * (ijcw[2] + 1));
	while (++ijcw[1] < ijcw[2])
	{
		if (str[ijcw[0] - ijcw[2] + ijcw[1]] != c)
			currdst[ijcw[1]] = str[ijcw[0] - ijcw[2] + ijcw[1]];
	}
	currdst[ijcw[1]] = 0;
	dest[ijcw[3]] = currdst;
	ijcw[3]++;
	ijcw[2] = 0;
}

void	ret_world(char **dest, char *str, char c)
{
	int		ijcw[4];

	ijcw[0] = -1;
	ijcw[3] = 0;
	ijcw[2] = 0;
	while (str[++ijcw[0]])
	{
		if (str[ijcw[0]] != c && str[ijcw[0] + 1])
			ijcw[2]++;
		else if (ijcw[2])
		{
			add_word(ijcw, str, dest, c);
		}
	}
}

char	**ft_split(char *str, char c)
{
	char	**dest;
	int		count;

	count = count_words(str, c);
	if (!(dest = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (count)
		ret_world(dest, str, c);
	dest[count] = 0;
	return (dest);
}