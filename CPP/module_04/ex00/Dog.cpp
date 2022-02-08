/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 13:59:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog is born" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog is gone" << std::endl;
}

Dog::Dog(Dog const &to_copy) {}

Dog &Dog::operator=(Dog const &rhs)
{
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Ouaff" << std::endl;
}
