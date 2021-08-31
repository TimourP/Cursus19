/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:23:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/23 09:34:24 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_quote(char *str, int i, char *quote)
{
	if (str[i] == '"' || str[i] == '\'')
	{
		if (*quote == str[i])
			*quote = 0;
		else if (*quote == 0 && is_in_str(&str[i] + 1, str[i]))
			*quote = str[i];
	}
}

static int	words_count_with_quotes(char *str, char c)
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
		if (i && str[i - 1] && str[i - 1] != c && str[i] == c && !quote)
		{
			count++;
			str[i] = 0;
		}
		else if (i && !str[i - 1] && str[i - 1] != c && str[i] == c && !quote)
			str[i] = 0;
	}
	if (str[i - 1] && str[i - 1] != c)
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

char	**parse_split_with_quotes(char *str, char c)
{
	const int	str_len = my_strlen(str);
	const int	w_count = words_count_with_quotes(str, c);
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
