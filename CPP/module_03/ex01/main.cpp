/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:58:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 15:25:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap defaultClap;
	ScavTrap withName("Julie");
	ScavTrap byCopy(withName);

	withName.attack("Joris");
	withName.takeDamage(7);
	withName.takeDamage(5);
	withName.beRepaired(8);
	withName.guardGate();
	return (0);
}