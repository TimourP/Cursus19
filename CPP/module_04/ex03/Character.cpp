/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:19:38 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 15:02:58 by tpetit           ###   ########.fr       */
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

Character::Character(std::string const name) : _name(name)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character::Character(Character const &to_copy) {
	this->_name = to_copy.getName();
	for (int i = 0; i < 4; i++)
	{
		if (to_copy._inventory[i])
			this->_inventory[i] = to_copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character &Character::operator=(Character const &rhs)
{
	this->_name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return *this;
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
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
