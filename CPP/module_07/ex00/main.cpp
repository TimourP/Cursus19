/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:09:04 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 12:50:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SomeFunctions.hpp"

int main(void)
{
	{
		int i = 4;
		int j = 7;
		std::cout << ::min(i, j) << std::endl;
		std::cout << ::max(i, j) << std::endl;
		std::cout << "i: " << i << "; j: " << j << std::endl;
		::swap(i, j);
		std::cout << "i: " << i << "; j: " << j << std::endl;
	}
	{
		char i = 'a';
		char j = 'b';
		std::cout << ::min(i, j) << std::endl;
		std::cout << ::max(i, j) << std::endl;
		std::cout << "i: " << i << "; j: " << j << std::endl;
		::swap(i, j);
		std::cout << "i: " << i << "; j: " << j << std::endl;
	}
	{
		double i = 4.9;
		double j = 7.8;
		std::cout << ::min(i, j) << std::endl;
		std::cout << ::max(i, j) << std::endl;
		std::cout << "i: " << i << "; j: " << j << std::endl;
		::swap(i, j);
		std::cout << "i: " << i << "; j: " << j << std::endl;
	}
	{
		int a = 2;
		int b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
		return 0;
	}
}