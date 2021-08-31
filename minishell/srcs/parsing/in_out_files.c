/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:05:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/17 13:10:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_in_out_loop(t_cmd *new, char *cmd, t_lst *new_file, int *i)
{
	new_file = lst_new(NULL);
	if (!new_file)
		return (1);
	if (cmd[*i + 1] == cmd[*i])
		new_file->flag = 1;
	if (cmd[*i] == '>')
		lst_add_back(&new->outfiles, new_file);
	else
		lst_add_back(&new->infiles, new_file);
	new_file->str = get_next_word(&cmd[*i + 1], i);
	if (!new_file->str)
		return (1);
	return (0);
}

static char	*get_in_out_init(char *cmd, int *i, int *j, char *quote)
{
	char	*new_cmd;

	if (!cmd)
		return (NULL);
	new_cmd = malloc(sizeof(char) * (my_strlen(cmd) + 1));
	if (!new_cmd)
		return (NULL);
	new_cmd[my_strlen(cmd)] = 0;
	*quote = 0;
	*i = -1;
	*j = -1;
	return (new_cmd);
}

char	*get_input_output(t_cmd *new, char *cmd)
{
	char	*new_cmd;
	int		i;
	int		j;
	char	quote;
	t_lst	*new_file;

	new_cmd = get_in_out_init(cmd, &i, &j, &quote);
	new_file = NULL;
	if (!new_cmd)
		return (NULL);
	while (cmd[++i])
	{
		set_quote(cmd, i, &quote);
		if (!quote && is_in_str("<>", cmd[i]))
		{
			if (get_in_out_loop(new, cmd, new_file, &i))
				return (NULL);
		}
		else if (++j > -1)
			new_cmd[j] = cmd[i];
	}
	new_cmd[j + 1] = 0;
	free(cmd);
	return (new_cmd);
}
