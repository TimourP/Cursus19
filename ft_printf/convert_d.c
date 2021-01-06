/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:43:31 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/06 13:29:17 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_d(ft_printf_data *print_variables)
{
	print_variables->current_str = ft_itoa_base(va_arg(print_variables->argc, int), 10, "0123456789");
	if (print_variables->min_length)
		if (!convert_width(print_variables))
			return (0);
	return (1);
}