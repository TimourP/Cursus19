/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:52:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/05 17:57:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_strjoin(char *first_string, char *second_string)
{
	int		i;
	char	*conc_str;

	if (first_string)
	{
		i = ft_strlen(first_string) + ft_strlen(second_string);
		if (!(conc_str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		conc_str[i] = 0;
		i = -1;
		while (first_string[++i])
			conc_str[i] = first_string[i];
		i = -1;
		while (second_string[++i])
			conc_str[i + ft_strlen(first_string)] = second_string[i];
		free(first_string);
		return (conc_str);
	}
	return (ft_strdup(second_string));
}

// char *join_back(char *malloced, char *add)
// {
	
// }

// char *join_front(char *malloced, char *add)
// {
	
// }
