/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:41:19 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/12 11:29:02 by tpetit           ###   ########.fr       */
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
	std::cout << i;
}

int main(void)
{
	std::vector<int> vect1(10);

	std::for_each(vect1.begin(), vect1.end(), editInt);
	std::for_each(vect1.begin(), vect1.end(), printInt);
	std::cout << std::endl;

	std::cout << *easyfind(vect1, 6) << std::endl;
	std::cout << *easyfind(vect1, 2) << std::endl;

	std::vector<int> vect2;

	try
	{
		std::cout << *easyfind(vect2, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << *easyfind(vect1, 19) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}