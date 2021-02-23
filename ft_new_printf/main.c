/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:32:40 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 11:48:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	const char test[100] = "str => %.3s\n";

	ft_printf(test, "hello");
	printf("---------------------------------\n");
	printf(test, "hello");
	printf("flags => %s", test);
	return (0);
}
