/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:06:18 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/18 15:40:59 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*create_shell_line(t_shell *shell, char **env)
{
	const int	status = shell->status;
	char		*line;
	char		*old_line;
	char		*pwd;

	if (status)
		line = my_strdup(RED "➜" BLU " minishell ( ");
	else
		line = my_strdup(GRN "➜" BLU " minishell ( " );
	pwd = get_env_value(shell, env, "PWD");
	old_line = line;
	line = my_strjoin(line, pwd);
	free(old_line);
	free(pwd);
	old_line = line;
	line = my_strjoin(line, " ) > " RESET);
	free(old_line);
	return (line);
}

/*
**	FORBIDDEN FCT rl_clear_history
*/

void	clear_shell(t_shell *shell)
{
	int		i;
	char	**env;

	rl_clear_history();
	env = shell->env;
	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
	cmd_clear(&shell->start_cmd);
	free(shell);
}

static void	main_loop(t_shell *shell, char *line, char *input)
{
	line = create_shell_line(shell, shell->env);
	input = readline(line);
	add_history(input);
	free(line);
	if (!input)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		init_edit_shell(3, NULL, 0);
		exit(0);
	}
	else if (!*input)
		;
	else if (!check_line(shell, input))
	{
		receive_signal();
		parse_line(shell, input);
		shell->cmd_start = 1;
		n_piper(shell);
	}
	shell->cmd_start = 0;
	free(input);
}

static void	set_shlvl(t_shell *shell)
{
	char	*env_var;
	char	*tmp;
	int		sh_lvl;
	char	**new_env;

	env_var = get_env_value(shell, shell->env, "SHLVL");
	sh_lvl = minishell_atoi(env_var);
	free(env_var);
	tmp = ft_itoa(sh_lvl + 1);
	if (sh_lvl >= 999)
	{
		write(STDOUT_FILENO, "minishell: warning: shell level (", 33);
		write(STDOUT_FILENO, tmp, my_strlen(tmp));
		write(STDOUT_FILENO, ") too high, resetting to 1\n", 27);
		env_var = my_strjoin("SHLVL=", "1");
	}
	else
		env_var = my_strjoin("SHLVL=", tmp);
	new_env = dispatch_if_yet(shell->env, env_var);
	if (new_env)
		shell->env = new_env;
	free(tmp);
	free(env_var);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;
	char	*input;
	char	*line;

	argc = (int)argc;
	argv = (void *)argv;
	line = NULL;
	input = NULL;
	shell = init_edit_shell(1, envp, 0);
	set_shlvl(shell);
	receive_signal();
	while (8)
	{
		signal(SIGQUIT, SIG_IGN);
		main_loop(shell, line, input);
	}
	clear_shell(shell);
	return (0);
}
