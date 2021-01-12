/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:37:26 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/12 13:47:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*join_back_c(char *malloced, char *add)
{
	int		i;
	char	*conc_str;

	if (malloced)
	{
		i = 1 + ft_strlen(add);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		conc_str[0] = malloced[0];
		i = -1;
		while (add[++i])
			conc_str[i + 1] = add[i];
		free(malloced);
		return (conc_str);
	}
	return (add ? ft_strdup(add) : NULL);
}

static int	convert_c_width(ft_printf_data *print_variables)
{
	char		*space_string;
	const int	remaining_length = print_variables->min_length - 1;

	if (!(space_string = string_with_length(' ',
		remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	if (print_variables->minus)
	{
		if (!(print_variables->current_str =
			join_back_c(print_variables->current_str, space_string)))
			return (free_and_return(space_string, 0));
	}
	else if (!(print_variables->current_str =
		join_front(print_variables->current_str, space_string)))
		return (free_and_return(space_string, 0));
	return (free_and_return(space_string, 1));
}

int			convert_c(ft_printf_data *print_variables)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[0] = va_arg(print_variables->argc, int);
	str[1] = 0;
	print_variables->current_str = ft_strdup(str);
	free(str);
	if (print_variables->min_length)
		if (!convert_c_width(print_variables))
			return (0);
	return (1);
}
