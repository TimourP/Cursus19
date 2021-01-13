/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:54:44 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/13 13:58:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_percent_dot_flag(t_printf_data *print_variables)
{
	char *zerostring;

	zerostring = string_with_length('0', print_variables->precision - 1);
	if (!(print_variables->current_str =
		join_front(print_variables->current_str, zerostring)))
		return (0);
	return (1);
}

int			convert_percent(t_printf_data *print_variables)
{
	print_variables->current_str = ft_strdup("%");
	if (print_variables->zero && print_variables->precision != -1)
		if (!convert_percent_dot_flag(print_variables))
			return (0);
	if (print_variables->min_length)
		if (!convert_width(print_variables))
			return (0);
	return (1);
}
