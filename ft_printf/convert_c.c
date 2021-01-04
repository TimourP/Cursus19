/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:37:26 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 17:47:31 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int convert_c(ft_printf_data *print_variables)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	str[0] = va_arg(print_variables->argc, int);
	str[1] = 0;
	print_variables->current_str = ft_strdup(str);
	free(str);
	return (1);
}