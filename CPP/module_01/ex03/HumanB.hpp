/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:14:43 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 10:09:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB( void );
		void	attack( void );
		void	setWeapon( Weapon& weapon );
	
	private:
		Weapon* _weapon;
		std::string _name;
};

#endif // HUMANB_H