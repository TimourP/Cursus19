/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 15:01:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
}

Animal::~Animal(void)
{
}

Animal::Animal(Animal const &to_copy) {}

Animal &Animal::operator=(Animal const &rhs)
{
	return *this;
}

std::string Animal::getType(void) const
{
	return this->_type;
}