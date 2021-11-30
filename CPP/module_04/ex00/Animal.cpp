/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 13:59:59 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {}

Animal::~Animal(void) {}

Animal::Animal(Animal const &to_copy) {}

Animal &Animal::operator=(Animal const &rhs)
{
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "I'm just a default animal, I have no sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return this->_type;
}