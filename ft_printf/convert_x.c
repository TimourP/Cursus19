/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:35:01 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/12 14:47:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_x_precision(ft_printf_data *print_variables)
{
	char	*space_string;
	int		remaining_length;

	remaining_length = print_variables->precision -
		ft_strlen(print_variables->current_str);
	if (!(space_string = string_with_length('0',
		remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	else if (!(print_variables->current_str =
		join_front(print_variables->current_str, space_string)))
		return (free_and_return(space_string, 0));
	return (free_and_return(space_string, 1));
}

int			convert_x(ft_printf_data *print_variables)
{
	int nb;

	nb = va_arg(print_variables->argc, unsigned int);
	print_variables->current_str = ft_itoa_base_u(nb, 16, "0123456789abcdef");
	if (print_variables->dot || print_variables->zero)
	{
		if (nb == 0)
			print_variables->current_str =
			ft_strdup(string_with_length('0', print_variables->precision));
		else if (!(convert_x_precision(print_variables)))
			return (0);
	}
	if (print_variables->min_length)
		if (!convert_width(print_variables))
			return (0);
	return (1);
}