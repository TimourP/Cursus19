/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/04 18:37:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>

typedef struct	ft_printf_data
{
	va_list argc;
	char current_char;
	char *current_str;
}				ft_printf_data;

int	ft_printf(const char *format, ...);

int convert_s(ft_printf_data *print_variables);
int convert_c(ft_printf_data *print_variables);
int convert_d(ft_printf_data *print_variables);
int convert_p(ft_printf_data *print_variables);
int convert_u(ft_printf_data *print_variables);
int convert_x(ft_printf_data *print_variables);
int convert_X(ft_printf_data *print_variables);

char	*ft_strdup(const char *str);
char	*ft_itoa_base(int n, int base_len, const char *base);
char	*ft_itoa_base_p(unsigned long long int n, int base_len, const char *base);
char	*ft_itoa_base_u(unsigned int n, int base_len, const char *base);

#endif