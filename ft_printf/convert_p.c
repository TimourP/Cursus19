/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:43:00 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/06 13:28:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_p(ft_printf_data *print_variables)
{
	unsigned long long int pointer_value;
	char *number;

	pointer_value = va_arg(print_variables->argc, unsigned long long int);
	number = ft_itoa_base_p(pointer_value, 16, "0123456789abcdef");
	print_variables->current_str = ft_strdup("0x");
	print_variables->current_str = join_back(print_variables->current_str, number);
	free(number);
	if (print_variables->min_length)
		if (!convert_width(print_variables))
			return (0);
	return (1);
}