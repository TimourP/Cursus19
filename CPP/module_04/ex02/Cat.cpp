/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:46 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 10:34:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
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

Cat::Cat(Cat const &to_copy) : AAnimal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	*this->_brain = *to_copy.getBrain();
}

Cat &Cat::operator=(Cat const &rhs)
{
	this->_type = "Cat";
	this->_brain = new Brain();
	*this->_brain = *rhs.getBrain();
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaouuuuu" << std::endl;
}