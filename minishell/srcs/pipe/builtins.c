/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 08:50:44 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/19 11:06:30 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	simple_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	return (s1[i] - s2[i]);
}

static int	atoc(char *str, unsigned char *status)
{
	size_t			i;
	char			neg;
	unsigned long	val;

	i = 0;
	neg = 0;
	val = 0;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		val *= 10;
		val += (str[i] - '0');
		if ((val > 2147483647 && !neg) || (val > 2147483648 && neg))
			return (-1);
		i++;
	}
	if (neg)
		val *= -1;
	*status = (unsigned char)val;
	return (0);
}

static int	exec_exit(t_cmd *cmd)
{
	unsigned char	exit_status;

	if (cmd->flags[1])
	{
		if (atoc(cmd->flags[1], &exit_status) < 0)
		{
			write(STDERR_FILENO, "minishell: exit: ", 17);
			write(STDERR_FILENO, cmd->flags[1], my_strlen(cmd->flags[1]));
			write(STDERR_FILENO, ": numeric argument required\n", 28);
			get_exit(2, cmd);
		}
		else if (cmd->flags[2])
		{
			write(STDERR_FILENO, "minishell: exit: too many arguments\n", 36);
			write(STDERR_FILENO, "exit\n", 6);
			return (MY_FILE_NOT_FOUND);
		}
		else
			get_exit(exit_status, cmd);
	}
	else
		get_exit(EXIT_SUCCESS, cmd);
	return (-1);
}

int	exec_builtin(t_cmd *cmd, char ***env)
{
	int	ret;

	ret = 257;
	if (!simple_strcmp(cmd->cmd, "env"))
		ret = get_env(*env, cmd);
	else if (!simple_strcmp(cmd->cmd, "echo"))
		ret = get_echo(cmd);
	else if (!simple_strcmp(cmd->cmd, "pwd"))
		ret = get_pwd();
	else if (!simple_strcmp(cmd->cmd, "cd"))
		ret = get_cd(cmd, env);
	else if (!simple_strcmp(cmd->cmd, "export"))
		ret = get_export(cmd, env);
	else if (!simple_strcmp(cmd->cmd, "unset"))
		ret = get_unset(cmd, env);
	else if (!simple_strcmp(cmd->cmd, "exit"))
		ret = exec_exit(cmd);
	if (ret != 257 && init_edit_shell(2, NULL, 0)->start_cmd->next)
		get_exit(EXIT_SUCCESS, cmd);
	return (ret);
}

int	check_builtins(char *cmd)
{
	if (!cmd)
		return (0);
	if (!simple_strcmp(cmd, "env") || !simple_strcmp(cmd, "echo")
		|| !simple_strcmp(cmd, "pwd") || !simple_strcmp(cmd, "cd")
		|| !simple_strcmp(cmd, "export") || !simple_strcmp(cmd, "unset")
		|| !simple_strcmp(cmd, "exit"))
		return (1);
	return (0);
}
