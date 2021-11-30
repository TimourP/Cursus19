/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:03:53 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 15:37:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::~AMateria(void) {}

AMateria::AMateria(AMateria const &to_copy) {}

AMateria &AMateria::operator=(AMateria const &rhs)
{
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