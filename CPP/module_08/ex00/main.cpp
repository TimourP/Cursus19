/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:41:19 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 16:06:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void editInt(int &i)
{
	static int u = 0;

	i = u;
	u++;
}

void printInt(int i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	std::vector<int> vect1(10);

	std::for_each(vect1.begin(), vect1.end(), editInt);
	std::for_each(vect1.begin(), vect1.end(), printInt);

	*easyfind<std::vector<int>>(vect1, 6) = 9;

	std::for_each(vect1.begin(), vect1.end(), printInt);
	return 0;
}