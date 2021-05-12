/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:11:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/12 14:11:59 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					neg;
	int					length;

	neg = 1;
	num = 0;
	length = -1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && ++length > -1)
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	if (!((*str >= 9 && *str <= 13) || *str == ' ' || *str == 0) || neg < 0)
		return (-1);
	return ((int)(num * neg));
}
