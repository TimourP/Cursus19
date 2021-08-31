/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:10:09 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/18 11:36:50 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	wait_pid_set_value(t_shell *shell, int pid)
{
	int	status;

	waitpid(pid, &status, WUNTRACED | WCONTINUED);
	if (shell)
		shell->status = status / 256;
}

static int	my_builtins(t_cmd *pip, char ***env, int infile, int outfile)
{
	int	ret;

	if (!check_builtins(pip->cmd) || pip->next)
		return (1);
	if (infile < 0 || outfile < 0)
		return (-1);
	ret = my_exec(pip, env, infile, outfile);
	return (ret);
}

static int	pipe_caller(t_cmd *cmd, t_shell *shell, int *files)
{
	int		fds[2];
	int		pid;

	if (pipe(fds) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (!pid)
		child_pipe(fds, cmd, &shell->env, files);
	else if (cmd->next->next)
		brother_pipe(fds, cmd->next, &shell->env);
	else
		parent_pipe(fds, cmd->next, &shell->env);
	return (0);
}

int	n_piper(t_shell *shell)
{
	int		pid;
	t_cmd	*cmd;
	int		files[2];

	cmd = shell->start_cmd;
	files[0] = multi_infiles(cmd, STDIN_FILENO);
	files[1] = multi_outfiles(cmd, STDOUT_FILENO);
	if (files[0] < 0 || files[1] < 0)
		return (-1);
	pid = my_builtins(cmd, &shell->env, files[0], files[1]);
	if (pid != 1)
		return (pid);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (!pid)
	{
		if (!cmd->next)
			my_exec(cmd, &shell->env, files[0], files[1]);
		else if (pipe_caller(cmd, shell, files) < 0)
			return (-1);
		get_exit(EXIT_SUCCESS, cmd);
	}
	wait_pid_set_value(shell, pid);
	return (0);
}
