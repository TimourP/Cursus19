/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:54:23 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/02 12:50:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0) {}

Fixed::Fixed(const Fixed &to_copy)
{
	this->_fixed = to_copy.getRawBits();
}

Fixed::Fixed(int initial)
{
	this->_fixed = initial << this->_fract_bit;
}
Fixed::Fixed(float initial)
{
	this->_fixed = roundf(initial * (1 << this->_fract_bit));
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	this->_fixed = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_fixed / (1 << this->_fract_bit);
}

int Fixed::toInt(void) const
{
	return this->_fixed >> 8;
}

std::ostream &operator<<(std::ostream &out, const Fixed &in)
{
	out << in.toFloat();
	return out;
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	Fixed f = *this;

	f.setRawBits(this->_fixed + rhs.getRawBits());
	return f;
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	Fixed f = *this;

	f.setRawBits(this->_fixed - rhs.getRawBits());
	return f;
}
Fixed Fixed::operator*(Fixed const &rhs)
{
	Fixed f = *this;

	f.setRawBits(this->_fixed * rhs.getRawBits() >> 8);
	return f;
}
Fixed Fixed::operator/(Fixed const &rhs)
{
	Fixed f(this->toFloat() / rhs.toFloat());

	return f;
}
Fixed &Fixed::operator++(void)
{
	this->_fixed++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed f = *this;
	this->_fixed++;
	return f;
}

Fixed &Fixed::operator--(void)
{
	this->_fixed--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed f = *this;
	this->_fixed--;
	return f;
}

bool Fixed::operator>(Fixed const &rhs) const
{
	if (this->_fixed > rhs.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator>=(Fixed const &rhs) const
{
	if (this->_fixed >= rhs.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator<(Fixed const &rhs) const
{
	if (this->_fixed < rhs.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator<=(Fixed const &rhs) const
{
	if (this->_fixed <= rhs.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator==(Fixed const &rhs) const
{
	if (this->_fixed == rhs.getRawBits())
		return (1);
	return (0);
}
bool Fixed::operator!=(Fixed const &rhs) const
{
	if (this->_fixed != rhs.getRawBits())
		return (1);
	return (0);
}

Fixed &Fixed::max(Fixed &fx1, Fixed &fx2)
{
	if (fx1 > fx2)
		return (fx1);
	return (fx2);
}

Fixed &Fixed::min(Fixed &fx1, Fixed &fx2)
{
	if (fx1 < fx2)
		return (fx1);
	return (fx2);
}

const Fixed &Fixed::max(Fixed const &fx1, Fixed const &fx2)
{
	if (fx1 > fx2)
		return (fx1);
	return (fx2);
}

const Fixed &Fixed::min(Fixed const &fx1, Fixed const &fx2)
{
	if (fx1 < fx2)
		return (fx1);
	return (fx2);
}