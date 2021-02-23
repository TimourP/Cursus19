/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:35:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 15:17:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_struct(t_printf_data *pf_var)
{
	if (pf_var->current_str)
		free(pf_var->current_str);
	pf_var->current_char = 0;
	pf_var->current_str = NULL;
	pf_var->minus = 0;
	pf_var->dot = 0;
	pf_var->zero = 0;
	pf_var->width = 0;
	pf_var->precision = -1;
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

int		is_in_str(char *str, char c)
{
	int i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int		ft_pf_atoi(t_printf_data *pr_var, const char *str, int *index)
{
	unsigned long long	num;
	int					length;
	int					neg;

	num = 0;
	neg = 1;
	length = -1;
	while (((*str >= 9 && *str <= 13) || *str == ' ') && ((*index)++ || 1))
		str++;
	while ((*str == '-' || *str == '0') && ((*index)++ || 1))
	{
		str++;
		if (*str == '-')
			neg = -1;
	}
	if (*str == '*' && ((*index)++ || 1))
		return (va_arg(pr_var->argc, int) * neg);
	while (*str >= '0' && *str <= '9' && ++length > -1)
	{
		num = 10 * num + (*str - '0');
		(*index)++;
		str++;
	}
	return ((int)(num * neg));
}

int		ft_stringify(t_printf_data *pf_var)
{
	if (pf_var->current_char == 's')
		return (convert_s(pf_var));
	else if (pf_var->current_char == 'c')
		return (convert_c(pf_var));
	else if (pf_var->current_char == 'd')
		return (convert_di(pf_var));
	else if (pf_var->current_char == 'p')
		return (convert_p(pf_var));
	else if (pf_var->current_char == 'i')
		return (convert_di(pf_var));
	else if (pf_var->current_char == 'u')
		return (convert_u(pf_var));
	else if (pf_var->current_char == 'x')
		return (convert_x(pf_var));
	else if (pf_var->current_char == 'X')
		return (convert_upperx(pf_var));
	else if (pf_var->current_char == '%')
		return (convert_percent(pf_var));
	return (1);
}
