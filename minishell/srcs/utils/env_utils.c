/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:48:31 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/12 15:38:17 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_value(t_shell *shell, char **env, char *var)
{
	int	i;

	i = -1;
	if (shell && var[0] == '?')
		return (ft_itoa(shell->status));
	while (env[++i])
	{
		if (my_strlen(var) < my_strlen(env[i]) && ft_strcmp(env[i], var) == 0
			&& env[i][my_strlen(var)] == '=')
			return (my_strdup(&env[i][my_strlen(var) + 1]));
	}
	return (my_strdup(""));
}
