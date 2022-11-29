/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:27:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/29 15:58:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VECTOR_H
#define TESTS_VECTOR_H

#include "../containers/vector.hpp"
#include "tests.hpp"
#include <vector>

#define TTest int

void print_ft_std(ft::vector<TTest> ft_vector, std::vector<TTest> std_vector, std::string title) {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	" << title << std::endl << std::endl;
	std::cout << "ft : ";
	for (ft::vector<TTest>::iterator i = ft_vector.begin(); i != ft_vector.end(); i++) {
		if (i != ft_vector.begin())
			std::cout << ", ";
		std::cout << *i;
	}

	std::cout << std::endl << "std: ";
	for (std::vector<TTest>::iterator i = std_vector.begin(); i != std_vector.end(); i++) {
		if (i != std_vector.begin())
			std::cout << ", ";
		std::cout << *i;
	}

	std::cout << std::endl << std::endl;
}

void print_ft_std_rev(ft::vector<TTest> ft_vector, std::vector<TTest> std_vector, std::string title) {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	" << title << std::endl << std::endl;
	std::cout << "ft : ";
	for (ft::vector<TTest>::reverse_iterator i = ft_vector.rbegin(); i != ft_vector.rend(); i++) {
		if (i != ft_vector.rbegin())
			std::cout << ", ";
		std::cout << *i;
	}

	std::cout << std::endl << "std: ";
	for (std::vector<TTest>::reverse_iterator i = std_vector.rbegin(); i != std_vector.rend(); i++) {
		if (i != std_vector.rend())
			std::cout << ", ";
		std::cout << *i;
	}

	std::cout << std::endl << std::endl;
}


void vector_tests(void) {
	ft::vector<TTest> ft_vector_empty;
	std::vector<TTest> std_vector_empty;

	print_ft_std(ft_vector_empty, std_vector_empty, "Empty constructor");

	std::srand(time(0));
	for (size_t i = 0; i < 8; i++)
	{
		TTest rand_int2 = std::rand() % 50;
		ft_vector_empty.push_back(rand_int2);
		std_vector_empty.push_back(rand_int2);
	}

	print_ft_std(ft_vector_empty, std_vector_empty, "Push");

	print_ft_std_value(ft_vector_empty.size(), std_vector_empty.size(), "Size");
}

#endif