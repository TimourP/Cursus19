/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiprocess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:11:38 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/17 13:06:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parent_pipe(int *fds, t_cmd *pip, char ***env)
{
	int		files[2];

	wait(0);
	close(fds[1]);
	files[0] = multi_infiles(pip, fds[0]);
	files[1] = multi_outfiles(pip, STDOUT_FILENO);
	if (files[0] < 0 || files[1] < 0 || dup2(files[0], STDIN_FILENO) < 0)
		return ;
	if (files[0] != fds[0])
		close(files[0]);
	close(fds[0]);
	if (files[1] != STDOUT_FILENO && dup2(files[1], STDOUT_FILENO) < 0)
		return ;
	if (files[1] != STDOUT_FILENO)
		close(files[1]);
	my_command(pip, pip->cmd, pip->flags, env);
	get_exit(EXIT_SUCCESS, pip);
}

static int	brother_child(int *new_fds, int *files, int *fds)
{
	close(new_fds[0]);
	if (dup2(files[0], STDIN_FILENO) < 0
		|| dup2(files[1], STDOUT_FILENO) < 0)
		return (-1);
	if (fds[0] != files[0])
		close(files[0]);
	close(fds[0]);
	if (files[1] != new_fds[1])
		close(files[1]);
	close(new_fds[1]);
	return (0);
}

void	brother_pipe(int *fds, t_cmd *pip, char ***env)
{
	int	pid;
	int	new_fds[2];
	int	files[2];

	wait(0);
	close(fds[1]);
	if (pipe(new_fds) == -1)
		return ;
	files[0] = multi_infiles(pip, fds[0]);
	files[1] = multi_outfiles(pip, new_fds[1]);
	if (files[0] < 0 || files[1] < 0)
		return ;
	pid = fork();
	if (pid < 0)
		return ;
	else if (!pid && brother_child(new_fds, files, fds) >= 0)
		my_command(pip, pip->cmd, pip->flags, env);
	else if (!pip->next->next)
		parent_pipe(new_fds, pip->next, env);
	else
		brother_pipe(new_fds, pip->next, env);
	get_exit(EXIT_SUCCESS, pip);
}

void	child_pipe(int *fds, t_cmd *pip, char ***env, int *files)
{
	close(fds[0]);
	if (files[1] == STDOUT_FILENO)
	{
		if (dup2(fds[1], STDOUT_FILENO) < 0)
			return ;
	}
	else if (dup2(files[1], STDOUT_FILENO) < 0)
		return ;
	close(fds[1]);
	if (files[1 != STDOUT_FILENO])
		close(files[1]);
	if (files[0] != STDIN_FILENO)
	{
		if (dup2(files[0], STDIN_FILENO) < 0)
			return ;
		close(files[0]);
	}
	my_command(pip, pip->cmd, pip->flags, env);
	get_exit(EXIT_SUCCESS, pip);
}
