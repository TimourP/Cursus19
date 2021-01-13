/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:52:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/13 13:57:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*join_back(char *malloced, char *add)
{
	int		i;
	char	*conc_str;

	if (malloced)
	{
		i = ft_strlen(malloced) + ft_strlen(add);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		i = -1;
		while (malloced[++i])
			conc_str[i] = malloced[i];
		i = -1;
		while (add[++i])
			conc_str[i + ft_strlen(malloced)] = add[i];
		free(malloced);
		return (conc_str);
	}
	return (add ? ft_strdup(add) : NULL);
}

char	*join_front(char *malloced, char *add)
{
	int		i;
	char	*conc_str;

	if (malloced)
	{
		i = ft_strlen(malloced) + ft_strlen(add);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		i = -1;
		while (add[++i])
			conc_str[i] = add[i];
		i = -1;
		while (malloced[++i])
			conc_str[i + ft_strlen(add)] = malloced[i];
		free(malloced);
		return (conc_str);
	}
	return (add ? ft_strdup(add) : NULL);
}

char	*string_with_length(char c, int length)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (++i < length)
		str[i] = c;
	str[i] = 0;
	return (str);
}

int		free_and_return(char *to_free, int to_return)
{
	free(to_free);
	return (to_return);
}

int		convert_width(t_printf_data *print_variables)
{
	char	*space_string;
	int		remaining_length;

	remaining_length = print_variables->min_length -
		ft_strlen(print_variables->current_str);
	if (!(space_string = string_with_length(' ',
		remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	if (print_variables->minus)
	{
		if (!(print_variables->current_str =
			join_back(print_variables->current_str, space_string)))
			return (free_and_return(space_string, 0));
	}
	else if (!(print_variables->current_str =
			join_front(print_variables->current_str, space_string)))
		return (free_and_return(space_string, 0));
	return (free_and_return(space_string, 1));
}
