/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 14:05:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <string>
# include <iostream>

class Cat {
	public:
		Cat( void );
		~Cat( void );
		Cat( Cat const & copy );
		Cat & operator=( Cat const & rhs );
	
	private:

};

#endif // CAT_H
	