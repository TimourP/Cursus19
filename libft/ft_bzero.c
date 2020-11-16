/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:45:45 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 14:59:40 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	int		i;
	char	*new_str;

	i = -1;
	new_str = (char *)str;
	while (++i < len)
		new_str[i] = 0;
	str = new_str;
}
