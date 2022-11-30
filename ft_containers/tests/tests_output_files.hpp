
#ifndef TESTS_O_H
#define TESTS_O_H

#include "../containers/map.hpp"
#include <map>
#include "../containers/vector.hpp"
#include <vector>
#include "../containers/stack.hpp"
#include <stack>

#include <iostream>
#include <istream>
#include <fcntl.h>
#include <fstream>
#include <sstream>

#define TTest int
#define KeyTest int

void print_in_out(ft::map<KeyTest, TTest>& ft_map, std::map<KeyTest, TTest>& std_map, std::ostream& ft_stream, std::ostream& std_stream) {
	for (ft::map<KeyTest, TTest>::iterator i = ft_map.begin(); i != ft_map.end(); i++) {
		if (i != ft_map.begin())
			ft_stream << ", ";
		ft_stream << (*i).first << "->" << (*i).second;
	}

	ft_stream << std::endl;

	for (std::map<KeyTest, TTest>::iterator i = std_map.begin(); i != std_map.end(); i++) {
		if (i != std_map.begin())
			std_stream << ", ";
		std_stream << (*i).first << "->" << (*i).second;
	}

	std_stream << std::endl;
}

void print_rev_in_out(ft::map<KeyTest, TTest>& ft_map, std::map<KeyTest, TTest>& std_map, std::ostream& ft_stream, std::ostream& std_stream) {
	for (ft::map<KeyTest, TTest>::reverse_iterator i = ft_map.rbegin(); i != ft_map.rend(); i++) {
		if (i != ft_map.rbegin())
			ft_stream << ", ";
		ft_stream << (*i).first << "->" << (*i).second;
	}

	ft_stream << std::endl;

	for (std::map<KeyTest, TTest>::reverse_iterator i = std_map.rbegin(); i != std_map.rend(); i++) {
		if (i != std_map.rbegin())
			std_stream << ", ";
		std_stream << (*i).first << "->" << (*i).second;
	}

	std_stream << std::endl;
}

void print_val_out(TTest ft_value, TTest std_value, std::ostream& ft_stream, std::ostream& std_stream) {
	ft_stream << ft_value << std::endl;
	std_stream << std_value << std::endl;
}

void print_val_out(size_t ft_value, size_t std_value, std::ostream& ft_stream, std::ostream& std_stream) {
	ft_stream << ft_value << std::endl;
	std_stream << std_value << std::endl;
}

void print_val_out(bool ft_value, bool std_value, std::ostream& ft_stream, std::ostream& std_stream) {
	ft_stream << (ft_value == true ? "True" : "False") << std::endl;
	std_stream << (std_value == true ? "True" : "False") << std::endl;
}

void test_out(void) {
	std::ofstream ft_stream;
	std::ofstream std_stream;
	ft_stream.open("outputs/ft.txt");
	std_stream.open("outputs/std.txt");

	// map tests

	ft::map<KeyTest, TTest> ft_map_empty;
	std::map<KeyTest, TTest> std_map_empty;

	print_in_out(ft_map_empty, std_map_empty, ft_stream, std_stream);

	ft_map_empty.insert(ft::make_pair(10, 5));

	std_map_empty.insert(std::make_pair(10, 5));

	print_in_out(ft_map_empty, std_map_empty, ft_stream, std_stream);

	std::srand(time(0));
	for (size_t i = 0; i < 80; i++)
	{
		KeyTest rand_int1 = std::rand() % 100;
		TTest rand_int2 = std::rand() % 100;
		ft_map_empty.insert(ft::make_pair(rand_int1, rand_int2));
		std_map_empty.insert(std::make_pair(rand_int1, rand_int2));
	}

	print_in_out(ft_map_empty, std_map_empty, ft_stream, std_stream);

	for (size_t i = 0; i < 100; i++)
	{
		KeyTest rand_int1 = std::rand() % 100;
		ft_map_empty.erase(rand_int1);
		std_map_empty.erase(rand_int1);
	}

	print_in_out(ft_map_empty, std_map_empty, ft_stream, std_stream);

	ft_map_empty.insert(ft::make_pair(987, 5));
	std_map_empty.insert(std::make_pair(987, 5));

	print_val_out(ft_map_empty[987], std_map_empty[987], ft_stream, std_stream);

	for (size_t i = 0; i < 10; i++)
	{
		KeyTest rand_int1 = std::rand() % 100;
		TTest rand_int2 = std::rand() % 100;
		ft_map_empty.insert(ft::make_pair(rand_int1, rand_int2));
		std_map_empty.insert(std::make_pair(rand_int1, rand_int2));
	}

	ft_map_empty.erase(ft_map_empty.begin());
	std_map_empty.erase(std_map_empty.begin());

	print_in_out(ft_map_empty, std_map_empty, ft_stream, std_stream);

	ft_map_empty.erase(++ft_map_empty.begin(), ++(++(++ft_map_empty.begin())));
	std_map_empty.erase(++std_map_empty.begin(), ++(++(++std_map_empty.begin())));

	for (size_t i = 0; i < 800; i++)
	{
		KeyTest rand_int1 = std::rand() % 1000;
		TTest rand_int2 = std::rand() % 1000;
		ft_map_empty.insert(ft::make_pair(rand_int1, rand_int2));
		std_map_empty.insert(std::make_pair(rand_int1, rand_int2));
	}

	print_in_out(ft_map_empty, std_map_empty, ft_stream, std_stream);
	print_val_out(ft_map_empty.size(), std_map_empty.size(), ft_stream, std_stream);

	ft_stream.close();
	std_stream.close();
}

#endif