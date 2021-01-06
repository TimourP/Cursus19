/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:43:31 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/06 17:47:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_d_precision_neg(ft_printf_data *print_variables)
{
	char *space_string;
	const int remaining_length = print_variables->precision - ft_strlen(print_variables->current_str) + 1;
	char *new_str;

	new_str = ft_strdup(&(print_variables->current_str)[1]);
	free(print_variables->current_str);
	if (!(space_string = string_with_length('0', remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	if (!(new_str = join_front(new_str, space_string)))
		return (free_and_return(space_string, 0));
	if (!(new_str = join_front(new_str, "-")))
		return (free_and_return(space_string, 0));
	print_variables->current_str = ft_strdup(new_str);
	free(new_str);
	return (free_and_return(space_string, 1));
}

int convert_d_precision(ft_printf_data *print_variables)
{
	char *space_string;
	const int remaining_length = print_variables->precision - ft_strlen(print_variables->current_str);

	if (!(space_string = string_with_length('0', remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	else if (!(print_variables->current_str = join_front(print_variables->current_str, space_string)))
		return (free_and_return(space_string, 0));
	return (free_and_return(space_string, 1));
}

int convert_d(ft_printf_data *print_variables)
{
	int nb;

	nb = va_arg(print_variables->argc, int);
	if (!(print_variables->current_str = ft_itoa_base(nb, 10, "0123456789")))
		return (0);
	if (print_variables->dot)
	{
		if (nb > 0)
		{
			if (!(convert_d_precision(print_variables)))
				return (0);
		}
		else
		{
			if (!(convert_d_precision_neg(print_variables)))
				return (0);
		}
	}
	if (print_variables->min_length)
		if (!convert_width(print_variables))
			return (0);
	return (1);
}