/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:16:39 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 15:10:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>

class ClapTrap {
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		~ClapTrap( void );
		ClapTrap( ClapTrap const & copy );
		ClapTrap & operator=( ClapTrap const & rhs );

		void attack( std::string const & target ) const;
		void takeDamage( unsigned int amount ) ;
		void beRepaired( unsigned int amount ) ;
	
	protected:
		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
};

#endif // CLAPTRAP_H
	