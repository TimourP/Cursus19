/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:50:15 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 17:07:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diam("Jhon");

	diam.whoAmI();
	diam.guardGate();
	diam.highFivesGuys();
	diam.attack("Jhon");
}