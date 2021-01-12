/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/12 14:04:39 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>

typedef struct	ft_printf_data
{
	va_list argc;
	char current_char;
	char *current_str;
	int minus;
	int min_length;
	int precision;
	int dot;
	int zero;
	int minus_but_dot;
}				ft_printf_data;

int	ft_printf(const char *format, ...);
char *join_front(char *malloced, char *add);
char *join_back(char *malloced, char *add);
char *string_with_length(char c, int length);
int	free_and_return(char *to_free, int to_return);
int convert_width(ft_printf_data *print_variables);

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
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str, int *index, ft_printf_data *print_variables);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup_spec(const char *str);

#endif