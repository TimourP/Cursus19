/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:32:40 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/23 10:48:12 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char test[10] = "%.1s\n";
	printf("flags : %s\n", test);
	printf(test, "12");
	printf("return : %d\n", ft_printf(test, "12"));
	return (0);
}