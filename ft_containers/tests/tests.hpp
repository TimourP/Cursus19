
#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <istream>
#include <fcntl.h>
#include <fstream>
#include <sstream>

#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


void map_test_print(void) {
	std::ifstream infile("./tests/map_tests.txt");
	std::stringstream ss;
	std::string str_resp;

	ss << infile.rdbuf();
	std::cout << std::endl << std::endl << std::endl;
	std::cout << KMAG << ss.str() << RST << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}

void vector_test_print(void) {
	std::ifstream infile("./tests/vector_tests.txt");
	std::stringstream ss;
	std::string str_resp;

	ss << infile.rdbuf();
	std::cout << std::endl << std::endl << std::endl;
	std::cout << KMAG << ss.str() << RST << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}

void stack_test_print(void) {
	std::ifstream infile("./tests/stack_tests.txt");
	std::stringstream ss;
	std::string str_resp;

	ss << infile.rdbuf();
	std::cout << std::endl << std::endl << std::endl;
	std::cout << KMAG << ss.str() << RST << std::endl;
	std::cout << std::endl << std::endl << std::endl;
}

#endif