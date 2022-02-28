/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:44:53 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/28 11:12:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	std::cout << "A zombie has risen from the dead" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " is dead, again..." << std::endl;
}

void Zombie::annonce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::name_zombie( std::string name )
{
	this->_name = name;
}