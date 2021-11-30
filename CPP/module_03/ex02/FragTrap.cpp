/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:33:56 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 12:37:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name = "BOB";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "FragTrap default constructor called. " << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "FragTrap constructor called. " << this->_name << " is born." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called. " << this->_name << " died." << std::endl;
}

FragTrap::FragTrap(FragTrap const &to_copy) : ClapTrap()
{
	this->_name = to_copy._name;
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	std::cout << "FragTrap copy constructor called. " << this->_name << " is born." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name << " is waiting for a willing highfive!" << std::endl;
}
