/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/21 17:17:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <unistd.h>
#include <time.h> 

template <typename T>
void showVector(ft::vector<T>& vect) {
	int i = -1;
	unsigned int size = vect.size();

	while (++i < size)
	{
		std::cout << "Hey: " << vect[i] << std::endl;
	}
	
}

int main(void)
{
	ft::vector<int> test(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.push_back(6);
	test.push_back(7);
	test.resize(50);
	showVector(test);
}