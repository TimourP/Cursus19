/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:23:29 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/22 19:18:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_data_end(t_printf_data *print_variables,
			const char *flags_set, int *i)
{
	if (flags_set[*i] == '0' && !print_variables->dot
		&& !print_variables->min_length)
	{
		if (flags_set[*i + 1] && flags_set[*i + 1] != '-')
		{
			print_variables->zero = 1;
			print_variables->precision =
				ft_atoi(&flags_set[*i + 1], i, print_variables);
			if (print_variables->precision < 0)
			{
				print_variables->minus = 1;
				print_variables->min_length = print_variables->precision;
				print_variables->precision = -1;
			}
		}
		else
		{
			print_variables->minus = 1;
			print_variables->min_length =
				ft_atoi(&flags_set[*i + 1], i, print_variables);
		}
	}
}

void	fill_data_dot(t_printf_data *print_variables,
			const char *flags_set, int *i)
{
	int curr_nbr;

	curr_nbr = ft_atoi(&flags_set[*i + 1], i, print_variables);
	if (print_variables->precision != -1)
		print_variables->min_length = print_variables->precision;
	if (curr_nbr >= 0)
	{
		print_variables->precision = curr_nbr;
		print_variables->dot = 1;
	}
}

int		fill_data(t_printf_data *print_variables, const char *flags_set)
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
			print_variables->min_length =
				ft_atoi(&flags_set[i], &i, print_variables);
		if (flags_set[i] == '.')
		{
			fill_data_dot(print_variables, flags_set, &i);
		}
		fill_data_end(print_variables, flags_set, &i);
		i++;
	}
	return (check_negative(len, print_variables));
}

int		ft_printf_loop(t_printf_data *print_variables, const char *str)
{
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
			if (!ft_stringify(print_variables))
				return (-1);
			write_str_and_count(print_variables, &charnum);
		}
	}
	return (charnum);
}

int		ft_printf(const char *format, ...)
{
	int				charnum;
	t_printf_data	*print_variables;

	if (!(print_variables = malloc(sizeof(t_printf_data))))
		return (-1);
	va_start(print_variables->argc, format);
	charnum = ft_printf_loop(print_variables, format);
	va_end(print_variables->argc);
	free(print_variables);
	return (charnum);
}
