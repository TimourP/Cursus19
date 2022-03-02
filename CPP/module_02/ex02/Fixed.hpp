/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:54:23 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/02 12:51:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <string>
# include <iostream>
# include <math.h>

class Fixed {
	public:
		Fixed( void );
		Fixed( const Fixed &to_copy );
		Fixed( int initial );
		Fixed( float initial );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed & operator=( Fixed const & rhs );
		Fixed operator+( Fixed const & rhs );
		Fixed operator-( Fixed const & rhs );
		Fixed operator*( Fixed const & rhs );
		Fixed operator/( Fixed const & rhs );
		Fixed & operator++( void );
		Fixed operator++( int );
		Fixed & operator--( void );
		Fixed operator--( int );

		bool	operator>( Fixed const & rhs) const;
		bool	operator>=( Fixed const & rhs) const;
		bool	operator<( Fixed const & rhs) const;
		bool	operator<=( Fixed const & rhs) const;
		bool	operator==( Fixed const & rhs) const;
		bool	operator!=( Fixed const & rhs) const;

		float toFloat(void) const;
		int toInt(void) const;

		static Fixed & max(Fixed & fx1, Fixed & fx2);
		static Fixed & min(Fixed & fx1, Fixed & fx2);

		const static Fixed & max(Fixed const & fx1, Fixed const & fx2);
		const static Fixed & min(Fixed const & fx1, Fixed const & fx2);
	
	private:
		int					_fixed;
		static const int	_fract_bit = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &in);

#endif // FIXED_H