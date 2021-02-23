/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:32:53 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 10:52:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

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
size_t			ft_strlen_until(char *str, char c);
int				is_in_str(char *str, char c);
int				ft_pf_atoi(t_printf_data *pr_var, const char *str, int *index);
int				ft_stringify(t_printf_data *pf_var);

#endif