/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:54:23 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/11 18:51:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include "string"
# include "iostream"

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
		Fixed & operator++( int rhs );
		Fixed & operator--( void );
		Fixed & operator--( int rhs);

		bool	operator>( Fixed const & rhs);
		bool	operator>=( Fixed const & rhs);
		bool	operator<( Fixed const & rhs);
		bool	operator<=( Fixed const & rhs);
		bool	operator==( Fixed const & rhs);
		bool	operator!=( Fixed const & rhs);

		float toFloat(void) const;
		int toInt(void) const;
	
	private:
		int					_fixed;
		static const int	fract_bit = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &in);

#endif // FIXED_H