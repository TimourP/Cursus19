/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:06:14 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 10:01:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	number_len(int n, int base_len)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n && ++i)
		n = n / base_len;
	return (i);
}

char	*ft_itoa_base(int n, int base_len, const char *base)
{
	const size_t	n_len = number_len(n, base_len);
	char			*num;
	int				i;
	int				neg;

	i = -1;
	neg = 0;
	if (n < 0)
		neg = 1;
	num = malloc(sizeof(char) * (n_len + 1 + (int)(n == 0)));
	if (!num)
		return (NULL);
	num[n_len + (int)(n == 0)] = 0;
	if (neg)
		num[0] = '-';
	if (n == 0)
		num[0] = base[0];
	while (n && ++i > -1)
	{
		num[n_len - 1 - i] = base[n % base_len * (-1 * neg)];
		n = n / base_len;
	}
	return (num);
}
