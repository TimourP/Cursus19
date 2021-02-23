/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:23:03 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 11:56:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_s_dot_flag(t_printf_data *pr_var)
{
	if (!(pr_var->current_str = ft_substr(pr_var->current_str,
		0, pr_var->precision)))
		return (0);
	if (pr_var->width)
		if (!convert_width(pr_var))
			return (0);
	return (1);
}

int			deal_s_flags(t_printf_data *pr_var)
{
	if (pr_var->dot && pr_var->precision != -1)
		if (!convert_s_dot_flag(pr_var))
			return (0);
	return (1);
}

int			convert_s(t_printf_data *pr_var)
{
	if (!(pr_var->current_str = ft_strdup_spec(va_arg(pr_var->argc, char*))))
		return (0);
	return (deal_s_flags(pr_var));
}
