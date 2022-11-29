/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/29 13:57:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/map_tests.hpp"
#include "tests/tests.hpp"

int main(void) {


	// vector tests
	vector_test_print();
	//map_tests();

	// stack tests
	stack_test_print();
	//map_tests();

	// map tests
	map_test_print();
	map_tests();

	return 0;
}
