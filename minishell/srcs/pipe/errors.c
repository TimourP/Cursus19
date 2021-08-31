/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:31:37 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/17 08:53:31 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exit_nopath(t_cmd *cmd, char *name, char *error, int ret)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, name, my_strlen(name));
	write(STDERR_FILENO, error, my_strlen(error));
	if (ret || cmd != init_edit_shell(2, NULL, 0)->start_cmd)
		get_exit(MY_FILE_NOT_FOUND, cmd);
	init_edit_shell(0, NULL, 1);
	if (!init_edit_shell(2, NULL, 0)->start_cmd->next)
		return (-1);
	return (0);
}

int	write_return(char *str, int ret)
{
	write(STDERR_FILENO, str, my_strlen(str));
	return (ret);
}
