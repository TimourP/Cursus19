/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:05:45 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/02 12:52:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << std::endl << "------------------" << std::endl << std::endl;
	}
	{
		Fixed a(19);
		Fixed b(19);
		std::cout << "=" << std::endl;
		std::cout << "(a: " << a << " ; b: " << b << ") "  << (a == b) << std::endl;
		a = a + 1;
		std::cout << "(a: " << a << " ; b: " << b << ") "  << (a == b) << std::endl;
		std::cout << ">" << std::endl;
		std::cout << "(a: " << a << " ; b: " << b << ") "  << (a > b) << std::endl;
		std::cout << "<" << std::endl;
		std::cout << "(a: " << a << " ; b: " << b << ") "  << (a < b) << std::endl;
	}
	{
		Fixed a(19);
		Fixed b(19);
		std::cout << "*" << std::endl;
		std::cout << "(a: " << a << " ; b: " << b << ") "  << (a * b) << std::endl;
		a = a + 1;
		std::cout << "(a: " << a << " ; b: " << b << ") "  << (a * b) << std::endl;
		b = b + 1;
		std::cout << "/" << std::endl;
		std::cout << "(a: " << a << " ; b: " << b << ") "  << (a / b) << std::endl;
		std::cout << "+" << std::endl;
		std::cout << "(a: " << a << " ; b: " << b << ") "  << (a + b) << std::endl;
	}
}