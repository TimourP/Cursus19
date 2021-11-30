/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:19:38 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 16:34:56 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("Steave")
{
	for (size_t i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::~Character(void) {}

Character::Character(Character const &to_copy) {}

Character &Character::operator=(Character const &rhs)
{
	return *this;
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
	}
}
