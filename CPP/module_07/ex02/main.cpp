/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:09:04 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 15:14:42 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> *arr = new Array<int>(4);
	Array<int> &arr_ref = *arr;

	arr_ref[0] = 90;

	std::cout << "DEFAULT TESTS" << std::endl;

	std::cout << arr_ref;

	try
	{
		arr_ref[10];
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		arr_ref[-1];
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << "COPY TESTS" << std::endl;

	Array<int> arr_copy(arr_ref);
	arr_ref[0] = 0;
	arr_copy[1] = 20;
	std::cout << "Initial: " << std::endl
			  << arr_ref;
	std::cout << "Copy: " << std::endl
			  << arr_copy;

	std::cout << std::endl;
	std::cout << "AFFECT TESTS" << std::endl;

	Array<int> arr_affect = arr_ref;
	arr_ref[0] = 50;
	arr_affect[1] = 20;
	std::cout << "Initial: " << std::endl
			  << arr_ref;
	std::cout << "Copy: " << std::endl
			  << arr_affect;
	delete arr;
}