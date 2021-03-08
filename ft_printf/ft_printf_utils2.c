/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:47:10 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/08 13:42:42 by tpetit           ###   ########.fr       */
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

int		free_and_return(char *to_free, int ret)
{
	free(to_free);
	to_free = NULL;
	return (ret);
}

int		convert_width(t_printf_data *pf_var)
{
	char	*space_string;
	char	char_to_fill;
	int		remaining_length;

	char_to_fill = pf_var->zero && !pf_var->minus ? '0' : ' ';
	remaining_length = pf_var->width - ft_strlen(pf_var->current_str);
	if (!(space_string = string_with_length(char_to_fill,
		remaining_length > 0 ? remaining_length : 0)))
		return (free_and_return(space_string, 0));
	if (pf_var->minus)
	{
		if (!(pf_var->current_str =
			join_back(pf_var->current_str, space_string)))
			return (free_and_return(space_string, 0));
	}
	else if (!(pf_var->current_str =
			join_front(pf_var->current_str, space_string)))
		return (free_and_return(space_string, 0));
	return (free_and_return(space_string, 1));
}

char	*join_back(char *malloced, char *add)
{
	int		i;
	char	*conc_str;

	if (!malloced)
		return (add ? ft_strdup(add) : NULL);
	i = ft_strlen(malloced) + ft_strlen(add);
	if (!(conc_str = malloc(sizeof(char) * (i + 1))))
	{
		free(malloced);
		return (NULL);
	}
	conc_str[i] = 0;
	i = -1;
	while (malloced[++i])
		conc_str[i] = malloced[i];
	i = -1;
	while (add[++i])
		conc_str[i + ft_strlen(malloced)] = add[i];
	free(malloced);
	return (conc_str);
}

char	*join_front(char *malloced, char *add)
{
	int		i;
	char	*conc_str;

	if (!malloced)
		return (add ? ft_strdup(add) : NULL);
	i = ft_strlen(malloced) + ft_strlen(add);
	if (!(conc_str = malloc(sizeof(char) * (i + 1))))
	{
		free(malloced);
		return (NULL);
	}
	conc_str[i] = 0;
	i = -1;
	while (add[++i])
		conc_str[i] = add[i];
	i = -1;
	while (malloced[++i])
		conc_str[i + ft_strlen(add)] = malloced[i];
	free(malloced);
	return (conc_str);
}
