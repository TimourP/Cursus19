/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:43:15 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 09:41:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
	public:
		Zombie( void );
		~Zombie( void );

		void annonce(void) const;
		void name_zombie( std::string name );

	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_H
