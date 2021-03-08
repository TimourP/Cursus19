/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 12:24:30 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/08 13:41:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	deal_c_flags(t_printf_data *pf_var, int diff)
{
	if (pf_var->width)
		if (!convert_width(pf_var))
			return (0);
	if (diff == 1 && !pf_var->minus)
		pf_var->current_str[pf_var->width - 1] = 0;
	else if (diff == 1)
		pf_var->current_str[0] = 0;
	return (1);
}

int			convert_c(t_printf_data *pf_var)
{
	char	*str;
	int		diff;

	str = malloc(sizeof(char) * 2);
	if (!(str))
		return (0);
	str[0] = va_arg(pf_var->argc, int);
	str[1] = 0;
	diff = str[0] == 0;
	pf_var->current_str = ft_strdup(str);
	free(str);
	return (deal_c_flags(pf_var, diff));
}
