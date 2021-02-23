/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:30:56 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/22 19:17:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_in_str(char *str, char c)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	write_and_add(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	write_str_and_count(t_printf_data *print_variables, int *count)
{
	if (print_variables->current_char)
	{
		if (print_variables->current_char == 'c')
		{
			write(1, print_variables->current_str,
			print_variables->min_length > 1 ? print_variables->min_length : 1);
			(*count) += print_variables->min_length > 1 ?
			print_variables->min_length : 1;
			free(print_variables->current_str);
			return ;
		}
		write(1, print_variables->current_str,
		ft_strlen(print_variables->current_str));
		(*count) += ft_strlen(print_variables->current_str);
		free(print_variables->current_str);
	}
}
