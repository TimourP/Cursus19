/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:59:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/06 13:27:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_s_dot_flag(ft_printf_data *print_variables)
{
	if (!(print_variables->current_str = ft_substr(print_variables->current_str,
		0, print_variables->precision)))
		return (0);
	return (1);
	
}

int convert_s(ft_printf_data *print_variables)
{
	if (!(print_variables->current_str = ft_strdup(va_arg(print_variables->argc, char*))))
		return (0);
	if (print_variables->dot)
		if (!convert_s_dot_flag(print_variables))
			return (0);
	if (print_variables->min_length)
		if (!convert_width(print_variables))
			return (0);
	return (1);
}