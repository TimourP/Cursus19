/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:23:29 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/05 18:43:40 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int is_in_str(char *str, char c){
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void write_and_add(char c, int *count){
	write(1, &c, 1);
	(*count)++;
}

void write_str_and_count(ft_printf_data *print_variables, int *count){
	if (print_variables->current_char){
		write(1, print_variables->current_str, ft_strlen(print_variables->current_str));
		(*count) += ft_strlen(print_variables->current_str);
	}
}

int init_data(ft_printf_data *print_variables){
	print_variables->current_char = 0;
	print_variables->current_str = NULL;
	print_variables->minus = 0;
	print_variables->dot = 0;
	print_variables->min_length = 0;
	print_variables->zero = 0;
	print_variables->precision = -1;
	return (1);
}

int add_converter_and_check(ft_printf_data *print_variables, char c)
{
	if (!is_in_str("cspdiuxX%", c))
		return (0);
	print_variables->current_char = c;
	return (1);
}

void print_struct(ft_printf_data *print_variables){
	printf("curr char : %c\n", print_variables->current_char);
	printf("curr str : %s\n", print_variables->current_str);
	printf("minus : %d\n", print_variables->minus);
	printf("min len : %d\n", print_variables->min_length);
	printf("zero : %d\n", print_variables->zero);
	printf("dot : %d\n", print_variables->dot);
	printf("curr precision : %d\n", print_variables->precision);
}

int ft_stringify(ft_printf_data *print_variables){
	if (print_variables->current_char == 's')
		convert_s(print_variables);
	else if (print_variables->current_char == 'c')
		convert_c(print_variables);
	else if (print_variables->current_char == 'd')
		convert_d(print_variables);
	if (print_variables->current_char == 'p')
		convert_p(print_variables);
	else if (print_variables->current_char == 'i')
		convert_d(print_variables);
	else if (print_variables->current_char == 'u')
		convert_u(print_variables);
	else if (print_variables->current_char == 'x')
		convert_x(print_variables);
	else if (print_variables->current_char == 'X')
		convert_X(print_variables);
	else if (print_variables->current_char == '%')
		print_variables->current_str = ft_strdup("%");
	return (1);
}

int fill_data(ft_printf_data *print_variables, const char* flags_set)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (flags_set[len] && is_in_str("0123456789-.*", flags_set[len]))
		len++;
	while (flags_set[i] && is_in_str("0123456789-.*", flags_set[i]))
	{
		if (flags_set[i] == '-' && i == 0)
			print_variables->minus = 1;
		if (i == 0 && flags_set[0] != '0')
			print_variables->min_length = ft_atoi(&flags_set[i], &i);
		if (flags_set[i] == '.')
		{
			print_variables->dot = 1;
			print_variables->precision = ft_atoi(&flags_set[i + 1], &i);
		}
		if (flags_set[i] == '0')
		{
			print_variables->zero = 1;
			print_variables->precision = ft_atoi(&flags_set[i + 1], &i);
		}
		i++;
	}
	return (len);
}

int ft_printf_loop(ft_printf_data *print_variables, const char *str){
	int charnum;
	int i;

	charnum = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != '%')
			write_and_add(str[i], &charnum);
		else if (++i)
		{
			init_data(print_variables);
			i += fill_data(print_variables, &str[i]);
			if (!add_converter_and_check(print_variables, str[i]))
				return (-1);
			ft_stringify(print_variables);
			write_str_and_count(print_variables, &charnum);
		}
	}
	print_struct(print_variables);
	return (charnum);
}

int	ft_printf(const char *format, ...)
{
	int charnum;
	ft_printf_data *print_variables;

	if (!(print_variables = malloc(sizeof(ft_printf_data))))
		return (-1);
	va_start(print_variables->argc, format);
	charnum = ft_printf_loop(print_variables, format);
	va_end(print_variables->argc);
	return (charnum);
}