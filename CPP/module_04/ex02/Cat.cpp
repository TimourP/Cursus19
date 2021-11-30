/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 14:52:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "I'm born as a cat" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "I'm dead as a cat" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return this->_brain;
}

Cat::Cat(Cat const &to_copy) : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	for (size_t i = 0; i < 100; i++)
	{
		this->_brain->haveIdea(to_copy.getBrain()->getIdea(i));
	}
}

Cat &Cat::operator=(Cat const &rhs)
{
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaouuuuu" << std::endl;
}