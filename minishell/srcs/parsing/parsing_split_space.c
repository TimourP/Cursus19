/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:01:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/19 14:11:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	i_s(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int	words_count_with_quotes(char *str)
{
	int		i;
	int		count;
	char	quote;

	i = -1;
	quote = 0;
	count = 0;
	if (str == NULL)
		return (0);
	while (str[++i])
	{
		set_quote(str, i, &quote);
		if (i && str[i - 1] && !i_s(str[i - 1]) && i_s(str[i]) && !quote)
		{
			count++;
			str[i] = 0;
		}
		else if (i && !str[i - 1] && !i_s(str[i - 1]) && i_s(str[i]) && !quote)
			str[i] = 0;
	}
	if (str[i - 1] && !i_s(str[i - 1]))
		count++;
	return (count);
}

static char	**free_split(char **split, int until)
{
	int	i;

	i = -1;
	while (++i < until)
		free(split[i]);
	free(split);
	return (NULL);
}

static int	parse_split_loop(char **split_list, char *str,
	int *current_word, int *i)
{
	if (str[*i] == 0)
		;
	else
	{
		split_list[*current_word] = my_strdup(&str[*i]);
		if (!split_list[*current_word])
		{
			free_split(split_list, *current_word);
			return (1);
		}
		*i += my_strlen(split_list[*current_word]) - 1;
		(*current_word)++;
	}
	return (0);
}

char	**parse_split_space(char *str)
{
	const int	str_len = my_strlen(str);
	const int	w_count = words_count_with_quotes(str);
	char		**split_list;
	int			i;
	int			current_word;

	if (!str[0])
	{
		split_list = malloc(sizeof(char *));
		if (!split_list)
			return (split_list);
		split_list[0] = NULL;
		return (split_list);
	}
	current_word = 0;
	i = -1;
	split_list = malloc(sizeof(char *) * (w_count + 1));
	if (!split_list)
		return (NULL);
	split_list[w_count] = NULL;
	while (++i < str_len)
		if (parse_split_loop(split_list, str, &current_word, &i))
			return (NULL);
	return (split_list);
}
