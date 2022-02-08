/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:54:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 14:01:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include <string>
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public virtual WrongAnimal {
public:
	WrongCat( void );
	~WrongCat( void );
	WrongCat( WrongCat const & copy );
	WrongCat & operator=( WrongCat const & rhs );

	void makeSound(void) const;

};

#endif // WRONGCAT_H
	