/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:43:35 by tpetit            #+#    #+#             */
/*   Updated: 2021/09/03 15:01:51 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_print(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr)
	{
		count = ft_print(nbr / 10);
		ft_putchar('0' + nbr % 10);
	}
	return (count + 1);
}

int	ft_putnbr(long nb)
{
	unsigned long	newnb;

	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nb < 0)
	{
		newnb = -nb;
		ft_putchar('-');
	}
	else
		newnb = nb;
	return (ft_print(newnb) - 1);
}
