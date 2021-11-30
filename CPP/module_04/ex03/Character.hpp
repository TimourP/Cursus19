/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:19:38 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 16:19:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public virtual ICharacter
{
public:
	Character(void);
	Character(std::string name);
	~Character(void);
	Character(Character const &copy);
	Character &operator=(Character const &rhs);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	std::string _name;
	AMateria *_inventory[4];
};

#endif // CHARACTER_H
