/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:50:43 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 15:59:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) {
	this->_name = "BOB";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "DiamondTrap default constructor called. " << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) {
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = FragTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap constructor called. " << this->_name << " is born." << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap destructor called. " << this->_name << " died." << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &to_copy ) {
	this->_name = to_copy._name;
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	std::cout << "DiamondTrap copy constructor called. " << this->_name << " is born." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const & rhs ) {
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

void DiamondTrap::whoAmI( void ) const
{
	std::cout << ClapTrap::_name << std::endl;
}