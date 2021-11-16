/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:44 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 14:05:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include <string>
# include <iostream>

class Dog {
	public:
		Dog( void );
		~Dog( void );
		Dog( Dog const & copy );
		Dog & operator=( Dog const & rhs );
	
	private:

};

#endif // DOG_H
	