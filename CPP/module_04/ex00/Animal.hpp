/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 14:05:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include <iostream>

class Animal {
	public:
		Animal( void );
		~Animal( void );
		Animal( Animal const & copy );
		Animal & operator=( Animal const & rhs );
	
	private:

};

#endif // ANIMAL_H
	