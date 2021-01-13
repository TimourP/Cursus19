/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:28:50 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/13 14:29:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_data(t_printf_data *print_variables)
{
	print_variables->current_char = 0;
	print_variables->current_str = NULL;
	print_variables->minus = 0;
	print_variables->dot = 0;
	print_variables->min_length = 0;
	print_variables->zero = 0;
	print_variables->precision = -1;
	return (1);
}

int		add_converter_and_check(t_printf_data *print_variables, char c)
{
	if (!is_in_str("cspdiuxX%", c))
		return (0);
	print_variables->current_char = c;
	return (1);
}

void	print_struct(t_printf_data *print_variables)
{
	printf("\n\ncurr char : %c\n", print_variables->current_char);
	printf("curr str : %s\n", print_variables->current_str);
	printf("minus : %d\n", print_variables->minus);
	printf("min len : %d\n", print_variables->min_length);
	printf("zero : %d\n", print_variables->zero);
	printf("dot : %d\n", print_variables->dot);
	printf("curr precision : %d\n\n\n", print_variables->precision);
}

int		ft_stringify(t_printf_data *print_variables)
{
	if (print_variables->current_char == 's')
		return (convert_s(print_variables));
	else if (print_variables->current_char == 'c')
		return (convert_c(print_variables));
	else if (print_variables->current_char == 'd')
		return (convert_d(print_variables));
	else if (print_variables->current_char == 'p')
		return (convert_p(print_variables));
	else if (print_variables->current_char == 'i')
		return (convert_d(print_variables));
	else if (print_variables->current_char == 'u')
		return (convert_u(print_variables));
	else if (print_variables->current_char == 'x')
		return (convert_x(print_variables));
	else if (print_variables->current_char == 'X')
		return (convert_upperx(print_variables));
	else if (print_variables->current_char == '%')
		return (convert_percent(print_variables));
	return (1);
}

int		check_negative(int len, t_printf_data *print_variables)
{
	if (print_variables->min_length < 0)
	{
		print_variables->min_length = 0 - print_variables->min_length;
		if (!print_variables->minus)
			print_variables->minus = 1;
	}
	if (print_variables->precision < 0)
		print_variables->precision = -1;
	return (len);
}
