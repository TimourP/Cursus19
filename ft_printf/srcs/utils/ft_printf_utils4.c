/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:47:36 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/19 22:39:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static size_t	number_len_p(unsigned long long int n, int base_len)
{
	int i;

	i = 0;
	while (n && ++i)
		n = n / base_len;
	return (i);
}

char			*ft_itoa_base_p(unsigned long long int n,
	int base_len, const char *base)
{
	const size_t	n_len = number_len_p(n, base_len);
	char			*num;
	int				i;
	int				neg;

	i = -1;
	neg = 0;
	if (!(num = malloc(sizeof(char) * (n_len + 1 + (int)(n == 0)))))
		return (NULL);
	num[n_len + (int)(n == 0)] = 0;
	if (neg)
		num[0] = '-';
	if (n == 0)
		num[0] = base[0];
	while (n && ++i > -1)
	{
		num[n_len - 1 - i] = neg ? base[n % base_len * -1] : base[n % base_len];
		n = n / base_len;
	}
	return (num);
}
