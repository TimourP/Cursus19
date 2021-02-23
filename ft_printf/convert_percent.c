/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:12:22 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 15:17:40 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			convert_percent(t_printf_data *pf_var)
{
	pf_var->current_str = ft_strdup("%");
	if (pf_var->width)
		if (!convert_width(pf_var))
			return (0);
	return (1);
}
