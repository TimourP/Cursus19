/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:54:23 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/02 11:39:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &to_copy ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed = to_copy.getRawBits();
}

Fixed::Fixed( int initial ) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = initial << this->_fract_bit;
}
Fixed::Fixed( float initial ) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(initial * (1 << this->_fract_bit));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixed = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_fixed / (1 << this->_fract_bit);
}

int Fixed::toInt(void) const {
	return  this->_fixed >> 8;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &in)
{
	out << in.toFloat();
	return out;
}