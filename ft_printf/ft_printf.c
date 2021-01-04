/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:23:29 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 16:03:33 by tpetit           ###   ########.fr       */
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

void write_and_add(char c, int *count){
	write(1, &c, 1);
	(*count)++;
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
		else
		{
			/* code */
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