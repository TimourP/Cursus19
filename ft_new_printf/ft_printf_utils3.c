/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:58:45 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 11:59:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string_with_length(char c, int length)
{
	int		i;
	char	*str;

	i = -1;
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (++i < length)
		str[i] = c;
	str[i] = 0;
	return (str);
}
