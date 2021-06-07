/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phi_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 23:08:29 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 18:39:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	phi_atoi(const char *str)
{
	unsigned long long	num;
	int					length;

	num = 0;
	length = -1;
	if (!(*str >= '0' && *str <= '9'))
		return (-1);
	while (*str >= '0' && *str <= '9' && ++length > -1)
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	if (*str != 0)
		return (-1);
	if (num > 2147483647 || length > 10)
		return (-1);
	return ((int)num);
}
