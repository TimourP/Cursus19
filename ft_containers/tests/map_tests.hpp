

#ifndef MAP_TESTS_H
#define MAP_TESTS_H

#include "../containers/map.hpp"
#include <map>

#define Key int
#define T int

void print_ft_std(ft::map<Key, T> ft_map, std::map<Key, T> std_map, std::string title) {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	" << title << std::endl << std::endl;
	std::cout << "ft : ";
	for (ft::map<Key, T>::iterator i = ft_map.begin(); i != ft_map.end(); i++) {
		if (i != ft_map.begin())
			std::cout << ", ";
		std::cout << (*i).first << "->" << (*i).second;
	}

	std::cout << std::endl << "std: ";
	for (std::map<Key, T>::iterator i = std_map.begin(); i != std_map.end(); i++) {
		if (i != std_map.begin())
			std::cout << ", ";
		std::cout << (*i).first << "->" << (*i).second;
	}

	std::cout << std::endl << std::endl;
}

void print_ft_std_rev(ft::map<Key, T> ft_map, std::map<Key, T> std_map, std::string title) {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	" << title << std::endl << std::endl;
	std::cout << "ft : ";
	for (ft::map<Key, T>::reverse_iterator i = ft_map.rbegin(); i != ft_map.rend(); i++) {
		if (i != ft_map.rbegin())
			std::cout << ", ";
		std::cout << (*i).first << "->" << (*i).second;
	}

	std::cout << std::endl << "std: ";
	for (std::map<Key, T>::reverse_iterator i = std_map.rbegin(); i != std_map.rend(); i++) {
		if (i != std_map.rbegin())
			std::cout << ", ";
		std::cout << (*i).first << "->" << (*i).second;
	}

	std::cout << std::endl << std::endl;
}


void print_ft_std_value(T ft_value, T std_value, std::string title) {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	" << title << std::endl << std::endl;
	std::cout << "ft : " << ft_value << std::endl;
	std::cout << "std: " << std_value << std::endl;
	std::cout << std::endl << std::endl;
}

void map_tests(void) {
	ft::map<Key, T> ft_map_empty;
	std::map<Key, T> std_map_empty;

	print_ft_std(ft_map_empty, std_map_empty, "Empty constructor");

	ft_map_empty.insert(ft::make_pair(1, 0));
	std_map_empty.insert(std::make_pair(1, 0));

	ft::map<Key, T> ft_map_copy(ft_map_empty);
	std::map<Key, T> std_map_copy(std_map_empty);

	print_ft_std(ft_map_copy, std_map_copy, "Copy constructor");

	ft::map<Key, T> ft_map_fill(ft_map_copy.begin(), ft_map_copy.end());
	std::map<Key, T> std_map_fill(std_map_copy.begin(), std_map_copy.end());

	print_ft_std(ft_map_copy, std_map_copy, "Iterator constructor");

	ft_map_empty.insert(ft::make_pair(10, 5));
	std_map_empty.insert(std::make_pair(10, 5));

	ft::map<Key, T> ft_map_equal;
	std::map<Key, T> std_map_equal;

	ft_map_equal = ft_map_empty;
	std_map_equal = std_map_empty;

	print_ft_std(ft_map_equal, std_map_equal, "Equal operator");

	print_ft_std_value(ft_map_equal[10], std_map_equal[10], "Operator []");

	std::srand(time(0));
	for (size_t i = 0; i < 8; i++)
	{
		Key rand_int1 = std::rand() % 50;
		T rand_int2 = std::rand() % 50;
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

	ft::map<Key, T> ft_map_empty_bis;
	std::map<Key, T> std_map_empty_bis;
	std::srand(time(0));
	for (size_t i = 0; i < 8; i++)
	{
		Key rand_int1 = std::rand() % 50;
		T rand_int2 = std::rand() % 50;
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

	system("leaks a.out");
}

#endif