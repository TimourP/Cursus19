/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldelmas <ldelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:58:21 by ldelmas           #+#    #+#             */
/*   Updated: 2021/08/19 17:32:29 by ldelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**strptradd(char **ptr, char *str)
{
	char	**new;
	char	*tmp;
	int		size;

	size = 0;
	while (ptr[size])
		size++;
	new = malloc(sizeof(*new) * (size + 2));
	tmp = malloc(sizeof(*tmp) * (my_strlen(str) + 1));
	if (!new || !tmp)
	{
		free(new);
		free(tmp);
		return ((void *)0);
	}
	size = -1;
	while (ptr[++size])
		new[size] = ptr[size];
	tmp = my_strcpy(str, tmp);
	new[size] = tmp;
	new[size + 1] = (void *)0;
	free(ptr);
	return (new);
}

char	**dispatch_if_yet(char **env, char *str)
{
	char	*s;
	int		i;
	char	*tmp;

	s = strdup_until_c(str, '=');
	if (!s)
		return (NULL);
	i = -1;
	while (env[++i])
	{
		if (ft_strcmp(env[i], s) == 0)
		{
			free(s);
			tmp = my_strdup(str);
			if (!tmp)
				return (NULL);
			free(env[i]);
			env[i] = tmp;
			return (env);
		}
	}
	free(s);
	return (strptradd(env, str));
}

int	get_export(t_cmd *cmd, char ***env)
{
	int		i;
	int		j;
	char	**old_env;

	if (!cmd->flags[1])
		return (get_env(*env, cmd));
	i = 0;
	while (cmd->flags[++i])
	{
		j = 0;
		while (cmd->flags[i][j] && cmd->flags[i][j] != '=')
			j++;
		if (!cmd->flags[i][j])
			continue ;
		old_env = *env;
		*env = dispatch_if_yet(*env, cmd->flags[i]);
		if (!(*env))
		{
			*env = old_env;
			return (-1);
		}
	}
	return (0);
}
