/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/22 17:21:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <unistd.h>
#include <time.h> 

template <typename T>
void showVector(ft::vector<T>& vect) {
	int i = -1;
	unsigned int size = vect.size();
	std::cout << "[ ";

	while (++i < size)
	{
		std::cout << vect[i];
		if (i != size - 1)
		{
			std::cout << ", ";
		}
	}
	size = vect.capacity();
	i--;
	if (i != size - 1)
	{
		std::cout << ", ";
	}
	while (++i < size)
	{
		std::cout << " ";
		if (i != size - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;
}

int main(void)
{
	ft::vector<int> test;
	for (size_t i = 0; i < 10; i++)
		test.push_back(i);
	
	ft::vector<int> test2(test);
	std::cout << test.max_size();

	showVector(test);
	showVector(test2);
}