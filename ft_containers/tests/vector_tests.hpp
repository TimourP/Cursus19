/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:27:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/29 16:32:29 by tpetit           ###   ########.fr       */
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

	ft::vector<TTest> ft_vector_size(10);
	std::vector<TTest> std_vector_size(10);

	print_ft_std(ft_vector_size, std_vector_size, "Size constructor");

	ft::vector<TTest> ft_vector_ite(ft_vector_size.begin(), ft_vector_size.end());
	std::vector<TTest> std_vector_ite(std_vector_size.begin(), std_vector_size.end());

	print_ft_std(ft_vector_ite, std_vector_ite, "Iterators constructor");

	ft::vector<TTest> ft_vector_copy(ft_vector_size);
	std::vector<TTest> std_vector_copy(std_vector_size);

	print_ft_std(ft_vector_copy, std_vector_copy, "Iterators constructor");

	ft::vector<TTest> ft_vector_equal = ft_vector_size;
	std::vector<TTest> std_vector_equal = std_vector_size;

	print_ft_std(ft_vector_equal, std_vector_equal, "Equal operator");

	std::srand(time(0));
	for (size_t i = 0; i < 8; i++)
	{
		TTest rand_int2 = std::rand() % 50;
		ft_vector_empty.push_back(rand_int2);
		std_vector_empty.push_back(rand_int2);
	}

	print_ft_std(ft_vector_empty, std_vector_empty, "Push");

	print_ft_std_value(ft_vector_empty.size(), std_vector_empty.size(), "Size");
	print_ft_std_value(ft_vector_empty.max_size(), std_vector_empty.max_size(), "Max size");

	ft_vector_empty.resize(32);
	std_vector_empty.resize(32);

	print_ft_std_value(ft_vector_empty.capacity(), std_vector_empty.capacity(), "Resize");
	print_ft_std_value(ft_vector_empty.empty(), std_vector_empty.empty(), "Empty");

	ft_vector_empty.reserve(64);
	std_vector_empty.reserve(64);

	print_ft_std_value(ft_vector_empty.capacity(), std_vector_empty.capacity(), "Reserve");
	print_ft_std_value(ft_vector_empty[0], std_vector_empty[0], "Operator[]");
	print_ft_std_value(ft_vector_empty.at(0), std_vector_empty.at(0), "At");
	print_ft_std_value(ft_vector_empty.front(), std_vector_empty.front(), "Front");
	print_ft_std_value(ft_vector_empty.back(), std_vector_empty.back(), "Back");

	ft_vector_empty.assign(ft_vector_copy.begin(), ft_vector_copy.end());
	std_vector_empty.assign(std_vector_copy.begin(), std_vector_copy.end());

	print_ft_std(ft_vector_empty, std_vector_empty, "Assign");

	ft_vector_empty.insert(++ft_vector_empty.begin(), 15);
	std_vector_empty.insert(++std_vector_empty.begin(), 15);

	print_ft_std(ft_vector_empty, std_vector_empty, "Insert");

	ft_vector_empty.insert(ft_vector_empty.begin(), 3, 1);
	std_vector_empty.insert(std_vector_empty.begin(), 3, 1);

	print_ft_std(ft_vector_empty, std_vector_empty, "Insert count");

	ft_vector_empty.insert(ft_vector_empty.begin(), ft_vector_empty.begin(), ft_vector_empty.end());
	std_vector_empty.insert(std_vector_empty.begin(), std_vector_empty.begin(), std_vector_empty.end());
}

#endif