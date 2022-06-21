/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/21 16:58:56 by tpetit           ###   ########.fr       */
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
	ft::vector<int> test(2);
	test.pop_back();
	test.push_back(4);

	showVector(test);
}