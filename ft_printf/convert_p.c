/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:43:00 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 18:20:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_p(ft_printf_data *print_variables)
{
	unsigned long long int pointer_value;

	pointer_value = va_arg(print_variables->argc, unsigned long long int);
	print_variables->current_str = ft_itoa_base(pointer_value, 16, "0123456789abcdef");
	return (1);
}