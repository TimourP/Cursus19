/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:23:03 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/08 13:41:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_s_dot_flag(t_printf_data *pf_var)
{
	if (!(pf_var->current_str = ft_substr(pf_var->current_str,
		0, pf_var->precision)))
		return (0);
	return (1);
}

static int	deal_s_flags(t_printf_data *pf_var)
{
	if (pf_var->dot && pf_var->precision != -1)
		if (!convert_s_dot_flag(pf_var))
			return (0);
	if (pf_var->width > 0)
		if (!convert_width(pf_var))
			return (0);
	return (1);
}

int			convert_s(t_printf_data *pf_var)
{
	if (!(pf_var->current_str = ft_strdup_spec(va_arg(pf_var->argc, char*))))
		return (0);
	return (deal_s_flags(pf_var));
}
