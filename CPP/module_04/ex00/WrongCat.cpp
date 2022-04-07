/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:54:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 14:02:15 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type = "WrongCat";
	std::cout << "WrongCat is born" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat is gone" << std::endl;
}

WrongCat::WrongCat(WrongCat const &to_copy) : WrongAnimal()
{
	this->_type = to_copy.getType();
}

WrongCat
	&
	WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Miaouuuuu" << std::endl;
}