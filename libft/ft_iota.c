/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:53:22 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 19:13:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	number_len(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n && ++i)
		n = n / 10;;
	return (i);
}

char	*ft_iota(int n)
{
	const size_t	n_len = number_len(n);
	char 			*num;
	int				i;
	int				neg;

	i = -1;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (!(num = malloc(sizeof(char) * (n_len + 1))))
		return (NULL);
	if (neg)
		num[0] = '-';
	while (n && ++i > -1)
	{
		if (neg)
			num[n_len - 1 - i] = '0' + (n % 10 * -1);
		else
			num[n_len - 1 - i] = '0' + n % 10;
		n = n / 10;
	}
	num[n_len] = 0;
	return (num);
}