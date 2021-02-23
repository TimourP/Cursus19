/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:53:43 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 15:03:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_u_precision(t_printf_data *pf_var)
{
	char	*space_string;
	int		remaining_length;

	remaining_length = pf_var->precision - ft_strlen(pf_var->current_str);
	if (!(space_string = string_with_length('0',
		remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	else if (!(pf_var->current_str =
		join_front(pf_var->current_str, space_string)))
		return (free_and_return(space_string, 0));
	return (free_and_return(space_string, 1));
}

static int	deal_u_flags(t_printf_data *pf_var, int nb)
{
	if (pf_var->dot || pf_var->zero)
	{
		if (nb == 0 && pf_var->precision != -1 && pf_var->dot)
		{
			free(pf_var->current_str);
			pf_var->current_str = string_with_length('0', pf_var->precision);
		}
		if (!(convert_u_precision(pf_var)))
			return (0);
	}
	if (pf_var->width)
		if (!convert_width(pf_var))
			return (0);
	return (1);
}

int			convert_u(t_printf_data *pf_var)
{
	int nb;

	nb = va_arg(pf_var->argc, unsigned int);
	if (!(pf_var->current_str = ft_itoa_base_u(nb, 10, "0123456789")))
		return (0);
	return (deal_u_flags(pf_var, nb));
}
