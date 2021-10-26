/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:39:55 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 10:53:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {}

Weapon::~Weapon( void ){}

std::string& Weapon::getType( void )
{
	std::string&	typeRef = this->_type;

	return (typeRef);
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}