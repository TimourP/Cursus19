/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:16 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 15:26:23 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	this->_name = "BOB";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap default constructor called. " << std::endl;
}

ScavTrap::ScavTrap( std::string name ) {
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap constructor called. " << this->_name << " is born." << std::endl;
}

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called. " << this->_name << " died." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &to_copy ) {
	this->_name = to_copy._name;
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	std::cout << "ScavTrap copy constructor called. " << this->_name << " is born." << std::endl;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const & rhs ) {
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

void ScavTrap::attack( std::string const & target ) const {
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << this->_name << " enterred in Gate keeper mode" << std::endl;
}