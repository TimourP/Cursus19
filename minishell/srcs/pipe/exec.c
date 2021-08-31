/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:10:09 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/17 13:05:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	pre_command(int tmp, int file, int usual)
{
	if (tmp < 0)
		return (-1);
	if (file != usual)
		if (file == -1 || dup2(file, usual) < 0)
			return (-1);
	return (0);
}

static int	post_command(int tmp, int file, int usual)
{
	if (file != usual)
	{
		close (file);
		if (dup2(tmp, usual) < 0)
			return (-1);
		close(tmp);
	}
	return (0);
}

int	my_exec(t_cmd *pip, char ***env, int infile, int outfile)
{
	int	std[2];

	std[0] = dup(STDIN_FILENO);
	std[1] = dup(STDOUT_FILENO);
	if (pre_command(std[0], infile, STDIN_FILENO) < 0
		|| pre_command(std[1], outfile, STDOUT_FILENO) < 0)
		return (-1);
	my_command(pip, pip->cmd, pip->flags, env);
	if (post_command(std[0], infile, STDIN_FILENO) < 0
		|| post_command(std[1], outfile, STDOUT_FILENO) < 0)
		return (-1);
	return (0);
}
