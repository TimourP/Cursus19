/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:27:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/29 15:55:17 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_STACK_H
#define TESTS_STACK_H

#include "../containers/stack.hpp"
#include <stack>
#include "tests.hpp"

#define TTest int

void print_ft_std(ft::stack<TTest> ft_stack, std::stack<TTest> std_stack, std::string title) {
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "	" << title << std::endl << std::endl;
	std::cout << "ft : ";
	ft::stack<TTest> ft_stack_copy(ft_stack);
	while (!ft_stack_copy.empty())
	{
		if (ft_stack.size() != ft_stack_copy.size())
			std::cout << ", ";
		std::cout << ft_stack_copy.top();
		ft_stack_copy.pop();
	}
	

	std::cout << std::endl << "std: ";
	std::stack<TTest> std_stack_copy(std_stack);
	while (!std_stack_copy.empty())
	{
		if (ft_stack.size() != std_stack_copy.size())
			std::cout << ", ";
		std::cout << std_stack_copy.top();
		std_stack_copy.pop();
	}

	std::cout << std::endl << std::endl;
}

void stack_tests(void) {
	ft::stack<TTest> ft_stack_empty;
	std::stack<TTest> std_stack_empty;

	print_ft_std(ft_stack_empty, std_stack_empty, "Empty constructor");

	std::srand(time(0));
	for (size_t i = 0; i < 8; i++)
	{
		TTest rand_int2 = std::rand() % 50;
		ft_stack_empty.push(rand_int2);
		std_stack_empty.push(rand_int2);
	}

	print_ft_std(ft_stack_empty, std_stack_empty, "Push");

	print_ft_std_value(ft_stack_empty.size(), std_stack_empty.size(), "Size");
	print_ft_std_value(ft_stack_empty.top(), std_stack_empty.top(), "Top");

	ft_stack_empty.pop();
	std_stack_empty.pop();
	print_ft_std(ft_stack_empty, std_stack_empty, "Pop");
}

#endif