/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:39:55 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/01 15:57:30 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {}

Weapon::~Weapon( void ){}

const std::string& Weapon::getType( void ) const
{
	const std::string&	typeRef = this->_type;

	return (typeRef);
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}