/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/12/01 11:19:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/map_tests.hpp"
#include "tests/stack_tests.hpp"
#include "tests/vector_tests.hpp"
#include "tests/tests.hpp"
#include "tests/tests_output_files.hpp"

int main(int argc, char **argv) {
	(void)argc;

	// all tests with diff
	test_out();

	// vector tests
	vector_test_print();
	vector_tests();

	// stack tests
	stack_test_print();
	stack_tests();

	// map tests
	map_test_print();
	map_tests();

	std::string leaks = "leaks ";
	std::string prog_name =  argv[0];
	prog_name = prog_name.substr(2);
	leaks += prog_name;

	system(leaks.c_str());

	std::cout << KRED << "Diff: " << std::endl;
	system("diff outputs/ft.txt outputs/std.txt");

	return 0;
}
