/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:04:18 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 10:04:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include "string"
# include "iostream"

class ClapTrap {
	public:
		ClapTrap( void );
		~ClapTrap( void );
		ClapTrap( ClapTrap const & copy );

		ClapTrap & operator=( ClapTrap const & rhs );
	
	private:

};

#endif // CLAPTRAP_H
	