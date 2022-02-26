/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:47:18 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 11:58:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _name("Bob")
{
	std::cout << "Data is born" << std::endl;
}

Data::Data(std::string const name) : _name(name)
{
	std::cout << "Data is born" << std::endl;
}

Data::~Data(void)
{
	std::cout << this->_name << " is gone" << std::endl;
}

Data::Data(Data const &to_copy) {}

Data &Data::operator=(Data const &rhs)
{
	return *this;
}

std::string Data::getName(void) const
{
	return this->_name;
}