/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:04:21 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/19 15:53:58 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		write(STDOUT_FILENO, cwd, my_strlen(cwd));
		write(STDOUT_FILENO, "\n", 1);
		return (SUCCESS);
	}
	else
		return (ERROR);
}
