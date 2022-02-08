/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:54:50 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 13:57:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	std::cout << "WrongAnimal is born" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal is gone" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &to_copy ) {}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const & rhs ) {
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "I'm just a default wrong animal, I have no sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->_type;
}