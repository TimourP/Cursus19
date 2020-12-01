/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:23:29 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/21 18:35:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int i;
	va_list argc;

	va_start(argc, 3);
	printf("%s\n", va_arg(argc, char*));
	printf("%s\n", va_arg(argc, char*));
	printf("%s\n", va_arg(argc, char*));
	i = -1;

	va_end(argc);
}