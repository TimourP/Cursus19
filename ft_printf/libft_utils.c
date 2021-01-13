/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:09:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/13 14:02:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	number_len_u(unsigned int n, int base_len)
{
	int i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n && ++i)
		n = n / base_len;
	return (i);
}

char			*ft_itoa_base_u(unsigned int n, int base_len, const char *base)
{
	const size_t	n_len = number_len_u(n, base_len);
	char			*num;
	int				i;
	int				neg;

	i = -1;
	neg = 0;
	if (n < 0)
		neg = 1;
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

static size_t	number_len(int n, int base_len)
{
	int i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n && ++i)
		n = n / base_len;
	return (i);
}

char			*ft_itoa_base(int n, int base_len, const char *base)
{
	const size_t	n_len = number_len(n, base_len);
	char			*num;
	int				i;
	int				neg;

	i = -1;
	neg = 0;
	if (n < 0)
		neg = 1;
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

char			*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	i = -1;
	while (str[++i])
		;
	if (!(dest = malloc((i + 1) * sizeof(char))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
