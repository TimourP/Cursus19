/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:41 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/07 10:03:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
}

AAnimal::~AAnimal(void)
{
}

AAnimal::AAnimal(AAnimal const &to_copy) {}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	return *this;
}

std::string AAnimal::getType(void) const
{
	return this->_type;
}