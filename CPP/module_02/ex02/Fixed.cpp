/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:54:23 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/11 18:23:15 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed = 0;
	return ;
}

Fixed::Fixed( const Fixed &to_copy ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed = to_copy.getRawBits();
}

Fixed::Fixed( int initial ) {
	this->_fixed = initial << this->fract_bit;
}
Fixed::Fixed( float initial ) {
	this->_fixed = initial * (1 << this->fract_bit);
	std::cout << this->_fixed << std::endl;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_fixed / (1 << this->fract_bit);
}

int Fixed::toInt(void) const {
	return  this->_fixed >> 8;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &in)
{
	out << in.toFloat();
	return out;
}

Fixed & Fixed::operator+( Fixed const & rhs )
{
	Fixed f;

	f.setRawBits(this->_fixed + rhs.getRawBits());
	return f;
}

Fixed & Fixed::operator-( Fixed const & rhs )
{

}
Fixed & Fixed::operator*( Fixed const & rhs )
{

}
Fixed & Fixed::operator/( Fixed const & rhs )
{

}
Fixed & Fixed::operator++( void )
{

}
Fixed & Fixed::operator++( int rhs )
{

}
Fixed & Fixed::operator--( void )
{

}
Fixed & Fixed::operator--( int rhs)
{

}

bool	Fixed::operator>( Fixed const & rhs)
{

}
bool	Fixed::operator>=( Fixed const & rhs)
{

}
bool	Fixed::operator<( Fixed const & rhs)
{

}
bool	Fixed::operator<=( Fixed const & rhs)
{

}
bool	Fixed::operator==( Fixed const & rhs)
{

}
bool	Fixed::operator!=( Fixed const & rhs)
{

}