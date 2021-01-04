/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:23:29 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 18:37:29 by tpetit           ###   ########.fr       */
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
	printf("\n");
	printf("curr char : %c\n", print_variables->current_char);
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
			while (is_in_str("0123456789-.*", str[i]))
			{
				i++;
			}
			if (!add_converter_and_check(print_variables, str[i]))
				return (-1);
			ft_stringify(print_variables);
			write_str_and_count(print_variables, &charnum);
		}
	}
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