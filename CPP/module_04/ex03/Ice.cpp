/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:09:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 14:39:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	this->_type = "ice";
}

Ice::~Ice(void) {}

Ice::Ice(Ice const &to_copy) {
	this->_type = to_copy.getType();
}

Ice &Ice::operator=(Ice const &rhs)
{
	return *this;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}

AMateria *Ice::clone() const
{
	Ice *clone = new Ice(*this);
	return clone;
}
