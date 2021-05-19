/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:37:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 22:35:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	convert_p(t_printf_data *pf_var)
{
	unsigned long long int	pointer_value;
	char					*number;

	pointer_value = va_arg(pf_var->argc, unsigned long long int);
	number = ft_itoa_base_p(pointer_value, 16, "0123456789abcdef");
	pf_var->current_str = ft_strdup("0x");
	if (!(pf_var->dot && pf_var->precision == 0 && pointer_value == 0))
		pf_var->current_str = join_back(pf_var->current_str, number);
	free(number);
	if (pf_var->width)
		if (!convert_width(pf_var))
			return (0);
	return (1);
}
