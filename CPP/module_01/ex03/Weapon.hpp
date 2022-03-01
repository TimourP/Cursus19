/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:36:41 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/01 15:55:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon( void );

		const std::string&	getType( void ) const;
		void			setType( std::string type );

	private:
		std::string _type;
};

#endif // WEAPON_H