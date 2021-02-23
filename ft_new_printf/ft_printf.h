/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:32:53 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 11:44:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

typedef struct	s_printf_data
{
	va_list	argc;
	char	current_char;
	char	*current_str;
	int		minus;
	int		dot;
	int		zero;
	int		width;
	int		precision;
}				t_printf_data;

int				ft_printf(const char *format, ...);
int				init_struct(t_printf_data *pf_var);
void			print_struct(t_printf_data *pf_var);
size_t			ft_strlen(const char *str);
int				is_in_str(char *str, char c);
int				ft_pf_atoi(t_printf_data *pr_var, const char *str, int *index);
int				ft_stringify(t_printf_data *pf_var);
void			write_and_add(int *count, char c);
void			write_str_and_add(t_printf_data *pf_var, int *count);
char			*ft_substr(char *s, unsigned int start, size_t len);

int				convert_s(t_printf_data *pf_var);
int				convert_c(t_printf_data *pf_var);
int				convert_percent(t_printf_data *pf_var);
int				convert_d(t_printf_data *pf_var);
int				convert_p(t_printf_data *pf_var);
int				convert_u(t_printf_data *pf_var);
int				convert_x(t_printf_data *pf_var);
int				convert_upperx(t_printf_data *pf_var);
char			*ft_strdup_spec(const char *str);
char			*ft_strdup(const char *str);

#endif
