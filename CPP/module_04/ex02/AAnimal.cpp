/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:41 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 10:09:57 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
}

AAnimal::~AAnimal(void)
{
}

AAnimal::AAnimal(AAnimal const &to_copy) : _type(to_copy.getType())
{
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	this->_type = rhs.getType();
	return *this;
}


std::string AAnimal::getType(void) const
{
	return this->_type;
}