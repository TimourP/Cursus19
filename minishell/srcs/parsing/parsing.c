/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:30:01 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/19 14:07:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int	init_parse_free(t_parse_free **parse_free)
{
	*parse_free = malloc(sizeof(t_parse_free));
	if (!parse_free)
		get_exit(MALLOC_ERROR, NULL);
	(*parse_free)->quote = 0;
	(*parse_free)->split_list = NULL;
	(*parse_free)->strip_list = NULL;
	(*parse_free)->strip = NULL;
	return (0);
}

static void	free_parse_free(t_parse_free *p)
{
	int	i;

	i = -1;
	while (p->split_list && p->split_list[++i])
		free(p->split_list[i]);
	i = -1;
	while (p->strip_list && p->strip_list[++i])
		free(p->strip_list[i]);
	free(p->strip_list);
	free(p->split_list);
	free(p->strip);
	get_exit(MALLOC_ERROR, NULL);
}

static void	parse_line_loop(t_shell *shell, t_parse_free *p, int i)
{
	t_cmd			*new;

	new = cmd_new(NULL, NULL);
	p->strip = replace_by_env_value(shell, p->split_list[i]);
	p->strip = get_input_output(new, p->strip);
	p->strip = my_strip(p->strip, ' ');
	if (!p->strip)
		free_parse_free(p);
	p->strip_list = parse_split_space(p->strip);
	if (remove_close_quote_from_lst(p->strip_list))
		free_parse_free(p);
	new->cmd = p->strip_list[0];
	new->flags = p->strip_list;
	cmd_add_back(&shell->start_cmd, new);
	free(p->strip);
	free(p->split_list[i]);
	p->split_list[i] = NULL;
}

int	parse_line(t_shell *shell, char *line)
{
	t_parse_free	*p;
	int				i;

	i = -1;
	init_parse_free(&p);
	cmd_clear(&shell->start_cmd);
	shell->start_cmd = NULL;
	p->split_list = parse_split_with_quotes(line, '|');
	if (!p->split_list)
		free_parse_free(p);
	while (p->split_list[++i] != NULL)
		parse_line_loop(shell, p, i);
	free(p->split_list);
	free(p);
	return (0);
}
