/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:11:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/03 17:17:29 by tpetit           ###   ########.fr       */
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
	return ((int)(num * neg));
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	write(1, str, i);
}

void	print_errors(int error)
{
	if (error == ARGS_NUMBER)
		ft_putstr("Error: number of args must be at least 1.\n");
	else if (error == ARGS_TYPE_ERROR)
		ft_putstr("Error: args must be integer type.\n");
	else if (error == MALLOC_ERROR)
		ft_putstr("Error: malloc fail.\n");
}

int	ft_strncmp(const char *s1, const char *s2)
{
	if (ft_strlen_until((char *)s1, 0) != ft_strlen_until((char *)s2, 0))
		return (-1);
	while (1)
	{
		if ((!*s1 || !*s2))
			return (0);
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
	}
}
