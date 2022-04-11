/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:09:04 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/11 13:33:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main(void)
{
	int int_a[3] = {1, 2, 3};
	iter(int_a, array_size(int_a), ft_print<int>);

	std::string str_a[2] = {"Hey", "Coucou"};
	iter(str_a, array_size(str_a), ft_print<std::string>);
}