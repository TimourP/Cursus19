/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:16:39 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/02 13:27:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "BOB";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "ClapTrap default constructor called. " << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "ClapTrap constructor called. " << this->_name << " is born." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called. " << this->_name << " died." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &to_copy)
{
	this->_name = to_copy._name;
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	std::cout << "ClapTrap copy constructor called. " << this->_name << " is born." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

void ClapTrap::attack(std::string const &target) const
{
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((int)amount > this->_hit_points)
	{
		std::cout << "ClapTrap " << this->_name << " took " << this->_hit_points << " points of damage! " << this->_name << " has no hitpoint left." << std::endl;
		this->_hit_points = 0;
		return;
	}
	this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage! " << this->_name << " still have " << this->_hit_points << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hit_points += amount;

	std::cout << "ClapTrap " << this->_name << " has been repaired with " << amount << " heal points! " << this->_name << " now have " << this->_hit_points << " hit points." << std::endl;
}