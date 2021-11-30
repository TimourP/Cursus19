/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 14:07:39 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "I'm born as a cat" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "I'm dead as a cat" << std::endl;
}

Cat::Cat(Cat const &to_copy) {}

Cat &Cat::operator=(Cat const &rhs)
{
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaouuuuu" << std::endl;
}