/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:25:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 18:32:17 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_u(ft_printf_data *print_variables)
{
	print_variables->current_str = ft_itoa_base_u(va_arg(print_variables->argc, unsigned int), 10, "0123456789");
	return (1);
}