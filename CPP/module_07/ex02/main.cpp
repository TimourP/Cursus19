/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:09:04 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/11 14:03:51 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	{
		std::cout << "MY MAIN" << std::endl;
		Array<int> numbers(5);
		Array<int> empty;

		std::cout << numbers << std::endl;
		numbers[0] = 45;
		numbers[4] = 455;
		try
		{
			numbers[-1] = 10;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[5] = 10;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << numbers << std::endl;
	}
	{
		std::cout << "MY MAIN TRY COPY" << std::endl;
		Array<int> numbers(5);
		numbers[0] = 45;
		numbers[4] = 455;

		Array<int> numbers_copy = numbers;
		numbers_copy[0] = 42;

		std::cout << numbers << std::endl;
		std::cout << numbers_copy << std::endl;
	}
    {
		std::cout << "DEFAULT MAIN" << std::endl;
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		delete [] mirror;//
		return 0;
	}
}