/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:18:54 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/02 11:57:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
	{
		Point p1(Fixed(0), Fixed(0));
		Point p2(Fixed(0), Fixed(5));
		Point p3(Fixed(5), Fixed(0));
		Point point(Fixed(1), Fixed(1));
		std::cout << bsp(p1, p2, p3, point) << std::endl;
	}
	{
		Point p1(Fixed(0), Fixed(0));
		Point p2(Fixed(0), Fixed(5));
		Point p3(Fixed(5), Fixed(0));
		Point point(Fixed(0), Fixed(0));
		std::cout << bsp(p1, p2, p3, point) << std::endl;
	}
	{
		Point p1(Fixed(0), Fixed(0));
		Point p2(Fixed(0), Fixed(5));
		Point p3(Fixed(5), Fixed(0));
		Point point(Fixed(33), Fixed(-99));
		std::cout << bsp(p1, p2, p3, point) << std::endl;
	}
	return 0;
}