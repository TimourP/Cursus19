/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:36:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 14:55:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap defaultClap;
	ClapTrap withName("Julie");
	ClapTrap byCopy(withName);

	withName.attack("Joris");
	withName.takeDamage(7);
	withName.takeDamage(5);
	withName.beRepaired(8);
	return (0);
}