/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:09:37 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 16:11:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	this->_type = "cure";
}

Cure::~Cure(void) {}

Cure::Cure(Cure const &to_copy) {}

Cure &Cure::operator=(Cure const &rhs)
{
	return *this;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	Cure *clone = new Cure();
	return clone;
}