/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_by_env_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:03:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/19 14:13:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*free_str_return(char *ret, char *free1, char *free2)
{
	free(free1);
	free(free2);
	return (ret);
}

static char	*set_new_str_env(t_shell *shell, char *str, int i, int *last_join)
{
	static char	open_quote = 0;
	char		*new_str;
	char		*env_var;
	char		*tmp;

	new_str = NULL;
	set_quote(str, i, &open_quote);
	if (str[i] == '$' && str[i + 1] && !(open_quote == '\''))
	{
		new_str = ft_substr(str, *last_join, i - *last_join);
		if (!new_str)
			return (NULL);
		env_var = strdup_until(&str[i + 1], "= \t\"'");
		if (!env_var)
			return (free_str_return(NULL, new_str, NULL));
		tmp = get_env_value(shell, shell->env, env_var);
		if (!tmp)
			return (free_str_return(NULL, new_str, env_var));
		new_str = parse_join(new_str, tmp);
		if (!new_str)
			return (free_str_return(NULL, env_var, NULL));
		*last_join = i + my_strlen(env_var) + 1;
		return (free_str_return(new_str, env_var, NULL));
	}
	return (my_strdup(""));
}

char	*replace_by_env_value(t_shell *shell, char *str)
{
	int		i;
	char	*new_str;
	int		last_join;
	char	*tmp;

	if (!str)
		return (NULL);
	i = -1;
	new_str = NULL;
	last_join = 0;
	while (str[++i])
	{
		tmp = set_new_str_env(shell, str, i, &last_join);
		if (!tmp)
			free_str_return(NULL, new_str, NULL);
		new_str = parse_join(new_str, tmp);
		if (!new_str)
			return (NULL);
	}
	if (last_join != i)
		new_str = parse_join(new_str, ft_substr(str, last_join, i - last_join));
	return (new_str);
}
