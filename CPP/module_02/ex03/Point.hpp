/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:07:57 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 14:12:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <string>
# include <iostream>
# include "Fixed.hpp"

class Point {
	public:
		Point( void );
		~Point( void );
		Point( Point const & copy );
		Point( Fixed const & x, Fixed const & y);

		Point & operator=( Point const & rhs );

		const Fixed & getX( void ) const;
		const Fixed & getY( void ) const;

		const float getXV( void ) const;
		const float getYV( void ) const;
	
	private:
		Fixed const _x;
		Fixed const _y;

};

#endif // POINT_H
	