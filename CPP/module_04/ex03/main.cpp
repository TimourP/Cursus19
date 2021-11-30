/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:22:56 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 16:35:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main(void)
{
	AMateria *c = new Cure();
	AMateria *i = new Ice();
	ICharacter *ch = new Character();

	std::cout << c->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << ch->getName() << std::endl;

	ch->equip(i);
	ch->equip(c);

	ch->use(0, *ch);
	ch->use(1, *ch);
	ch->use(2, *ch);
	ch->use(3, *ch);

	delete c;
	delete i;
	delete ch;
	return (0);
}