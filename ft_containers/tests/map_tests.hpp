/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:34:52 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/29 15:55:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_TESTS_H
#define MAP_TESTS_H

#include "../containers/map.hpp"
#include <map>
#include "tests.hpp"

#define KeyTest int
#define TTest int

void print_ft_std(ft::map<KeyTest, TTest> ft_map, std::map<KeyTest, TTest> std_map, std::string title) {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	" << title << std::endl << std::endl;
	std::cout << "ft : ";
	for (ft::map<KeyTest, TTest>::iterator i = ft_map.begin(); i != ft_map.end(); i++) {
		if (i != ft_map.begin())
			std::cout << ", ";
		std::cout << (*i).first << "->" << (*i).second;
	}

	std::cout << std::endl << "std: ";
	for (std::map<KeyTest, TTest>::iterator i = std_map.begin(); i != std_map.end(); i++) {
		if (i != std_map.begin())
			std::cout << ", ";
		std::cout << (*i).first << "->" << (*i).second;
	}

	std::cout << std::endl << std::endl;
}

void print_ft_std_rev(ft::map<KeyTest, TTest> ft_map, std::map<KeyTest, TTest> std_map, std::string title) {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	" << title << std::endl << std::endl;
	std::cout << "ft : ";
	for (ft::map<KeyTest, TTest>::reverse_iterator i = ft_map.rbegin(); i != ft_map.rend(); i++) {
		if (i != ft_map.rbegin())
			std::cout << ", ";
		std::cout << (*i).first << "->" << (*i).second;
	}

	std::cout << std::endl << "std: ";
	for (std::map<KeyTest, TTest>::reverse_iterator i = std_map.rbegin(); i != std_map.rend(); i++) {
		if (i != std_map.rbegin())
			std::cout << ", ";
		std::cout << (*i).first << "->" << (*i).second;
	}

	std::cout << std::endl << std::endl;
}

void map_tests(void) {
	ft::map<KeyTest, TTest> ft_map_empty;
	std::map<KeyTest, TTest> std_map_empty;

	print_ft_std(ft_map_empty, std_map_empty, "Empty constructor");

	ft_map_empty.insert(ft::make_pair(1, 0));
	std_map_empty.insert(std::make_pair(1, 0));

	ft::map<KeyTest, TTest> ft_map_copy(ft_map_empty);
	std::map<KeyTest, TTest> std_map_copy(std_map_empty);

	print_ft_std(ft_map_copy, std_map_copy, "Copy constructor");

	ft::map<KeyTest, TTest> ft_map_fill(ft_map_copy.begin(), ft_map_copy.end());
	std::map<KeyTest, TTest> std_map_fill(std_map_copy.begin(), std_map_copy.end());

	print_ft_std(ft_map_copy, std_map_copy, "Iterator constructor");

	ft_map_empty.insert(ft::make_pair(10, 5));
	std_map_empty.insert(std::make_pair(10, 5));

	ft::map<KeyTest, TTest> ft_map_equal;
	std::map<KeyTest, TTest> std_map_equal;

	ft_map_equal = ft_map_empty;
	std_map_equal = std_map_empty;

	print_ft_std(ft_map_equal, std_map_equal, "Equal operator");

	print_ft_std_value(ft_map_equal[10], std_map_equal[10], "Operator []");

	std::srand(time(0));
	for (size_t i = 0; i < 8; i++)
	{
		KeyTest rand_int1 = std::rand() % 50;
		TTest rand_int2 = std::rand() % 50;
		ft_map_empty.insert(ft::make_pair(rand_int1, rand_int2));
		std_map_empty.insert(std::make_pair(rand_int1, rand_int2));
	}

	print_ft_std(ft_map_empty, std_map_empty, "Use of iterators");
	print_ft_std_rev(ft_map_empty, std_map_empty, "Use of reverse iterators");

	ft_map_empty.erase(ft_map_empty.begin());
	std_map_empty.erase(std_map_empty.begin());

	print_ft_std(ft_map_empty, std_map_empty, "Erase the first");

	ft_map_empty.erase(++ft_map_empty.begin(), ++(++(++ft_map_empty.begin())));
	std_map_empty.erase(++std_map_empty.begin(), ++(++(++std_map_empty.begin())));

	print_ft_std(ft_map_empty, std_map_empty, "Erase the second and the third");
	
	ft_map_empty.erase(ft_map_empty.begin(), ft_map_empty.end());
	std_map_empty.erase(std_map_empty.begin(), std_map_empty.end());

	print_ft_std(ft_map_empty, std_map_empty, "Erase all");

	ft::map<KeyTest, TTest> ft_map_empty_bis;
	std::map<KeyTest, TTest> std_map_empty_bis;
	std::srand(time(0));
	for (size_t i = 0; i < 8; i++)
	{
		KeyTest rand_int1 = std::rand() % 50;
		TTest rand_int2 = std::rand() % 50;
		ft_map_empty.insert(ft::make_pair(rand_int1, rand_int2));
		std_map_empty.insert(std::make_pair(rand_int1, rand_int2));

		rand_int1 = std::rand() % 50;
		rand_int2 = std::rand() % 50;
		ft_map_empty_bis.insert(ft::make_pair(rand_int1, rand_int2));
		std_map_empty_bis.insert(std::make_pair(rand_int1, rand_int2));
	}

	print_ft_std(ft_map_empty, std_map_empty, "Before swap map 1");
	print_ft_std(ft_map_empty_bis, std_map_empty_bis, "Before swap map 2");

	ft_map_empty.swap(ft_map_empty_bis);
	std_map_empty.swap(std_map_empty_bis);

	print_ft_std(ft_map_empty, std_map_empty, "After swap map 1");
	print_ft_std(ft_map_empty_bis, std_map_empty_bis, "After swap map 2");

	print_ft_std_value((*ft_map_empty.find((*ft_map_empty.begin()).first)).first, (*std_map_empty.find((*std_map_empty.begin()).first)).first, "Find");
	print_ft_std_value((*ft_map_empty.upper_bound((*ft_map_empty.begin()).first)).first, (*std_map_empty.upper_bound((*std_map_empty.begin()).first)).first, "Upper bound");
	print_ft_std_value((*ft_map_empty.lower_bound((*ft_map_empty.begin()).first)).first, (*std_map_empty.lower_bound((*std_map_empty.begin()).first)).first, "Lower bound");

	ft_map_empty.clear();
	std_map_empty.clear();

	print_ft_std(ft_map_empty, std_map_empty, "Clear");

	system("leaks a.out");
}

#endif