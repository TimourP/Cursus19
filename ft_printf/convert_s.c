/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:59:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 17:47:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_s(ft_printf_data *print_variables)
{
	if (!(print_variables->current_str = ft_strdup(va_arg(print_variables->argc, char*))))
		return (0);
	return (1);
}