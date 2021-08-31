/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:46:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/08/17 11:17:42 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	number_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i = 1;
	while (n && ++i)
		n = n / 10;
	return (i);
}

char	*ft_itoa(int n)
{
	const size_t	n_len = number_len(n);
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
		num[0] = '0';
	while (n && ++i > -1)
	{
		num[n_len - 1 - i] = '0' + n % 10;
		if (neg)
			num[n_len - 1 - i] = '0' + n % 10 * -1;
		n = n / 10;
	}
	return (num);
}

int	minishell_atoi(char *str)
{
	unsigned long long	num;

	num = 0;
	if (my_strlen(str) > 10 || !str[0])
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	if (*str || num > 2147483646)
		return (0);
	return (num);
}

size_t	str_list_len(char **str_list)
{
	size_t	i;

	i = -1;
	while (str_list[++i])
		;
	return (i);
}

void	free_str_list(char **str_list)
{
	int	i;

	i = -1;
	while (str_list[++i])
		free(str_list[i]);
	free(str_list);
}
