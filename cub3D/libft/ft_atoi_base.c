/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:58:56 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 15:06:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_inbase(char *base, char c)
{
	int	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (1);
	return (0);
}

static int	test_error(char *base, int *baselen)
{
	int	i;
	int	j;

	i = -1;
	while (base[++i])
		if (base[i] == '-' || base[i] == '+')
			return (1);
	if (i <= 1)
		return (1);
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[j++])
		{
			if (base[j] == base[i] && i != j)
				return (1);
		}
	}
	i = -1;
	while (base[++i])
		;
	*baselen = 0;
	*baselen = i;
	return (0);
}

static int	calculate_to_add(char *base, int baselen, char c, int puiss)
{
	int	index;
	int	i;
	int	value;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
		{
			index = i;
			break ;
		}
	}
	i = -1;
	value = 1;
	while (++i < puiss)
	{
		value *= baselen;
	}
	return (value * index);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	baselen;
	int	max;

	num = 0;
	max = 0;
	test_error(base, &baselen);
	while (check_inbase(base, str[++max]))
		;
	while (check_inbase(base, *str))
	{
		num += calculate_to_add(base, baselen, *str, max - 1);
		str++;
		max--;
	}
	return (num);
}
