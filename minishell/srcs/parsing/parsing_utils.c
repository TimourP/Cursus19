/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:08:49 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/11 11:30:18 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_close_quote_loop(char *str, int i, int *j, char *new_str)
{
	static char	open_quote;

	if ((str[i] == '"' || str[i] == '\'') && open_quote == 0
		&& is_in_str(&str[i + 1], str[i]))
		open_quote = str[i];
	else if ((str[i] == '"' || str[i] == '\'') && open_quote == str[i])
		open_quote = 0;
	else
	{
		new_str[*j] = str[i];
		*j = *j + 1;
	}
}

static char	*remove_close_quote(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = -1;
	j = 0;
	new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[++i])
		remove_close_quote_loop(str, i, &j, new_str);
	new_str[j] = 0;
	free(str);
	return (new_str);
}

int	remove_close_quote_from_lst(char **lst)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!lst)
		return (1);
	while (lst[++i])
	{
		tmp = remove_close_quote(lst[i]);
		if (!tmp)
			return (1);
		lst[i] = tmp;
	}
	return (0);
}
