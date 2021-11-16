/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:34:03 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 15:47:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap withName("Julie");

	withName.attack("Joris");
	withName.takeDamage(7);
	withName.takeDamage(5);
	withName.beRepaired(8);
	withName.highFivesGuys();
	return (0);
}