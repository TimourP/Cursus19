/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:35:01 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/06 13:29:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_x(ft_printf_data *print_variables)
{
	print_variables->current_str = ft_itoa_base_u(
		va_arg(print_variables->argc, unsigned int), 16, "0123456789abcdef");
	if (print_variables->min_length)
		if (!convert_width(print_variables))
			return (0);
	return (1);
}