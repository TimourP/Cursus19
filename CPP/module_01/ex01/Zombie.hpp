/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:43:15 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 09:05:31 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {
	public:
		Zombie( std::string name );
		~Zombie( void );

		void annonce(void);

	private:
		std::string _name;
};

Zombie*	newZombie( std::string name );
void randomChump( std::string name );

#endif // ZOMBIE_H
