/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:11:20 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/04 11:27:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *str, t_stack **stack)
{
	long	num;
	int		neg;
	int		length;

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
	if ((num * neg) > (long)(2147483647) || (num * neg)
		< (long)(-2147483648) || length > 9)
		exit_message(ARGS_TYPE_ERROR, stack);
	return ((int)(num * neg));
}

void	ft_putstr(const char *str)
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
		write(2, "Error\n", 6);
	else if (error == ARGS_TYPE_ERROR)
		write(2, "Error\n", 6);
	else if (error == MALLOC_ERROR)
		write(2, "Error: malloc fail\n", 19);
	else if (error == DUPLICATES_ARGS)
		write(2, "Error\n", 6);
}

void	exit_message(int error, t_stack **stack)
{
	ft_stackclear(stack);
	print_errors(error);
	exit(EXIT_FAILURE);
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
