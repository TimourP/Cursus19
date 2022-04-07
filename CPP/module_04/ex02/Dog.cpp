/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/07 10:03:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
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

Dog &Dog::operator=(Dog const &rhs)
{
	return *this;
}

Brain *Dog::getBrain(void) const
{
	return this->_brain;
}

Dog::Dog(Dog const &to_copy) : AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	for (size_t i = 0; i < 100; i++)
	{
		this->_brain->haveIdea(to_copy.getBrain()->getIdea(i));
	}
}

void Dog::makeSound(void) const
{
	std::cout << "Ouaff" << std::endl;
}
