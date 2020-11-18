/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/18 11:21:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_print(unsigned int nbr, int fd)
{
	if (nbr)
	{
		ft_print(nbr / 10, fd);
		ft_putchar('0' + nbr % 10, fd);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	newnb;

	if (nb == 0)
		ft_putchar('0', fd);
	if (nb < 0)
	{
		newnb = -nb;
		ft_putchar('-', fd);
	}
	else
		newnb = nb;
	ft_print(newnb, fd);
}
