/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:18:54 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 11:04:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void print_point( Point const & p )
{
	std::cout << "x:" << p.getX() << " y:" << p.getY() <<std::endl;
}

float sign(Point const & p1, Point const & p2, Point const & p3)
{
	return (p1.getX().toFloat() - p3.getX().toFloat()) * (p2.getY().toFloat() - p3.getY().toFloat()) - (p2.getX().toFloat() - p3.getX().toFloat()) * (p1.getY().toFloat() - p3.getY().toFloat());
}

bool isInTriangle(Point const & p1, Point const & p2, Point const & p3, Point const & point)
{
	float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(point, p1, p2);
    d2 = sign(point, p2, p3);
    d3 = sign(point, p3, p1);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

int main(void) {
	Point p1(Fixed(0), Fixed(0));
	Point p2(Fixed(0), Fixed(5));
	Point p3(Fixed(1), Fixed(0));
	Point point(Fixed(0), Fixed(0));
	std::cout << isInTriangle(p1, p2, p3, point) << std::endl;
	return 0;
}