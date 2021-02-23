/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:47:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 11:48:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_struct(t_printf_data *pf_var)
{
	printf("curr str : %s\n", pf_var->current_str);
	printf("curr char : %c\n", pf_var->current_char);
	printf("minus : %d\n", pf_var->minus);
	printf("width : %d\n", pf_var->width);
	printf("zero : %d\n", pf_var->zero);
	printf("dot : %d\n", pf_var->dot);
	printf("curr precision : %d\n", pf_var->precision);
}
