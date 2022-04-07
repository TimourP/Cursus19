/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:46 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 13:53:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat is born" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat is gone" << std::endl;
}

Cat::Cat(Cat const &to_copy) : Animal()
{
	this->_type = to_copy.getType();
}

Cat &Cat::operator=(Cat const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaouuuuu" << std::endl;
}