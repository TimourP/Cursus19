/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/13 14:32:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <limits.h>

typedef struct	s_printf_data
{
	va_list	argc;
	char	current_char;
	char	*current_str;
	int		minus;
	int		min_length;
	int		precision;
	int		dot;
	int		zero;
	int		minus_but_dot;
}				t_printf_data;

int				ft_printf(const char *format, ...);
char			*join_front(char *malloced, char *add);
char			*join_back(char *malloced, char *add);
char			*string_with_length(char c, int length);
int				free_and_return(char *to_free, int to_return);
int				convert_width(t_printf_data *print_variables);
int				check_negative(int len, t_printf_data *print_variables);
int				ft_stringify(t_printf_data *print_variables);
void			print_struct(t_printf_data *print_variables);
int				add_converter_and_check(t_printf_data *print_variables, char c);
int				init_data(t_printf_data *print_variables);
void			write_str_and_count(t_printf_data *print_variables, int *count);
void			write_and_add(char c, int *count);
int				is_in_str(char *str, char c);

int				convert_s(t_printf_data *print_variables);
int				convert_c(t_printf_data *print_variables);
int				convert_percent(t_printf_data *print_variables);
int				convert_d(t_printf_data *print_variables);
int				convert_p(t_printf_data *print_variables);
int				convert_u(t_printf_data *print_variables);
int				convert_x(t_printf_data *print_variables);
int				convert_upperx(t_printf_data *print_variables);

char			*ft_strdup(const char *str);
char			*ft_itoa_base(int n, int base_len, const char *base);
char			*ft_itoa_base_p(unsigned long long int n,
				int base_len, const char *base);
char			*ft_itoa_base_u(unsigned int n,
				int base_len, const char *base);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str,
				int *index, t_printf_data *print_variables);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup_spec(const char *str);

#endif
