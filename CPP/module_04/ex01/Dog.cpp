/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 10:24:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "I'm born as a dog" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "I'm dead as a dog" << std::endl;
}

Dog::Dog(Dog const &to_copy) : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	*this->_brain = *to_copy.getBrain();
}


Dog &Dog::operator=(Dog const &rhs)
{
	this->_type = "Cat";
	this->_brain = new Brain();
	*this->_brain = *rhs.getBrain();
	return *this;
}

Brain *Dog::getBrain(void) const
{
	return this->_brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Ouaff" << std::endl;
}
