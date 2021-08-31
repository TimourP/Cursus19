/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:49:37 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/17 11:49:56 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	init_shell_env(t_shell *shell, char **env)
{
	int				i;
	const size_t	env_len = str_list_len(env);
	char			**env_copy;

	i = -1;
	env_copy = malloc(sizeof(char *) * (env_len + 1));
	if (env_copy == NULL)
		return (ERROR);
	env_copy[env_len] = NULL;
	while (env[++i])
	{
		env_copy[i] = my_strdup(env[i]);
		if (env_copy[i] == NULL)
		{
			free_str_list(env_copy);
			return (ERROR);
		}
	}
	i = -1;
	shell->env = env_copy;
	return (SUCCESS);
}

t_shell	*init_edit_shell(int is_init, char **env, int status)
{
	static t_shell	*shell;

	if (is_init == 2)
		return (shell);
	else if (is_init == 3)
	{
		clear_shell(shell);
		return (NULL);
	}
	else if (is_init)
	{
		shell = malloc(sizeof(t_shell));
		if (!shell)
			return (NULL);
		shell->start_cmd = NULL;
		shell->status = 0;
		shell->cmd_start = 0;
		init_shell_env(shell, env);
		return (shell);
	}
	if (shell)
		shell->status = status;
	return (NULL);
}
