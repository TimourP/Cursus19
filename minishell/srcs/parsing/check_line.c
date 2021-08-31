/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:37:58 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/19 14:12:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	return_check(t_shell *shell)
{
	shell->status = 1;
	write(STDERR_FILENO, "minishell: syntax error\n", 24);
	return (1);
}

static int	is_next_in(char *str, char *set)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ')
		{
			j = -1;
			while (set[++j])
				if (set[j] == str[i])
					return (1);
			break ;
		}
	}
	return (0);
}

static int	only_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!i_s(str[i]))
			return (0);
	return (1);
}

int	check_line(t_shell *shell, char *line)
{
	int		i;
	char	quote;

	i = -1;
	quote = 0;
	if (line && is_next_in(line, "|"))
		return (return_check(shell));
	if (only_space(line))
		return (1);
	while (line[++i])
	{
		set_quote(line, i, &quote);
		if (quote)
			continue ;
		if (line[i] == '|' && is_next_in(&line[i + 1], "|"))
			return (return_check(shell));
		if (line[i] == '>' && is_next_in(&line[i + 1], "<"))
			return (return_check(shell));
		if (line[i + 1] && line [i + 2] && is_in_str("<>", line[i])
			&& is_next_in(&line[i + 1], "<>") && is_next_in(&line[i + 2], "<>"))
			return (return_check(shell));
	}
	return (0);
}
