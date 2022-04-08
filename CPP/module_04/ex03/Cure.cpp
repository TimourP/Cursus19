/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:09:37 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 10:41:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	this->_type = "cure";
}

Cure::~Cure(void) {}

Cure::Cure(Cure const &to_copy) {
	this->_type = to_copy.getType();
}

Cure &Cure::operator=(Cure const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}