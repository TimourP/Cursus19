/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:07:57 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 10:40:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(Fixed(0)), _y(Fixed(0)) {}

Point::~Point( void ) {}

Point::Point( Point const &to_copy ) : _x(Fixed(to_copy.getX())), _y(Fixed(to_copy.getX())) {}

Point::Point( Fixed const & x, Fixed const & y) : _x(Fixed(x.toFloat())), _y(Fixed(y.toFloat())) {}

Point	&Point::operator=( Point const & rhs ) {
	return *this;
}

const Fixed & Point::getX( void ) const {
	return (this->_x);
}

const Fixed & Point::getY( void ) const {
	return (this->_y);
}