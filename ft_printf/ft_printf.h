/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 16:50:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	ft_printf_data
{
	va_list argc;
	char current_char;
	char *current_str;
}				ft_printf_data;

int	ft_printf(const char *format, ...);

#endif