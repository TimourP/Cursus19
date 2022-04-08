/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:03:53 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 10:38:48 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
	std::cout << "Amateria is born" << std::endl;
}

AMateria::AMateria( std::string const & type) : _type(type) {}

AMateria::~AMateria(void) {
	std::cout << "AMateria is gone" << std::endl;
}

AMateria::AMateria(AMateria const &to_copy) : _type(to_copy.getType()) {}

AMateria &AMateria::operator=(AMateria const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Default use on " << target.getName();
}